#include "../headers/gamePlay.h"
#include "../headers/menu.h"
#include "../headers/Matches.h"
#include "../headers/player.h"
#include "../headers/Team.h"
#include <iostream>

gamePlay::gamePlay(void)
{
    batters.resize(2);
    gamePlayBalls = 0;
    gamePlayRuns = 0;
    gamePlayOut = 0;
    gamePlayOvers = 0;
    // toBat=boTeamA;
    // toBowl=boTeamB;
    isBatting = 'A';
    isBowling = 'B';
    setBounds();
}
void gamePlay::gameDisplay(void)
{
    system("clear");
    print("---------------------------------", 2);
    print("Welcome To Cricket Match Console", 2);
    print("---------------------------------", 2);

    print("Match Teams : " + teams.first + " vs " + teams.second, 2);

    print("Runs Scored/Out : " + std::to_string(gamePlayRuns) + "/" + std::to_string(gamePlayOut));
    print(" Overs : " + std::to_string(gamePlayOvers) + "." + std::to_string(gamePlayBalls), 2);

    print("Striker : " + batters[0].first, 2);
    print("Non Striker : " + batters[1].first, 2);
    print("Bowler : " + bowler.first, 4);

    getGameStatus();
}

void gamePlay::setBounds(void)
{
    gamePlayOutBound = 10;
    std::string query = "SELECT MatchType From Matches Where MatchID=" + std::to_string(gamePlayMatchId);
    std::string result;
    try
    {
        if (!execute_query(query))
        {
            throw 0;
        }

        res = mysql_use_result(conn);

        row = mysql_fetch_row(res);

        if (row != NULL)
        {
            std::string result = row[0];
        }

        if (result == "T20")
        {
            gamePlayOverBound = 20;
        }
        else if (result == "ODI")
        {
            gamePlayOverBound = 50;
        }
        else
        {
            //Handle Custom Scene of 90 Overs Per Day Later
            gamePlayOverBound = 90;
        }

        mysql_free_result(res);
    }
    catch (int e)
    {
        print("This Operation has issues", 1);
    }
}
void gamePlay::getGameStatus(void)
{
    int choice;

    print("***********************************************", 2);
    print("Select Runs Scored at Overs " + std::to_string(gamePlayOvers) + "." + std::to_string(gamePlayBalls), 2);
    print("1. Sixer", 2);
    print("2. Four-Boundary", 2);
    print("3. Out", 2);
    print("4. Enter The Runs", 2);
    print("Any other value to stop this operation", 3);

    print("Enter Your Choice: ", 0);
    std::cin >> choice;
    getchar();

    std::string query;

    if (choice == 1)
    {
        gamePlayRuns += 6;
        query = "INSERT INTO ScoreCard VALUES (" + std::to_string(gamePlayBalls) + "," + std::to_string(gamePlayOvers) + "," + std::to_string(6) + "," + std::to_string(gamePlayMatchId) + ",\"" + batters[0].first + "\",\"" + bowler.first + "\")";
    }
    else if (choice == 2)
    {
        gamePlayRuns += 4;
        query = "INSERT INTO ScoreCard VALUES (" + std::to_string(gamePlayBalls) + "," + std::to_string(gamePlayOvers) + "," + std::to_string(4) + "," + std::to_string(gamePlayMatchId) + ",\"" + batters[0].first + "\",\"" + bowler.first + "\")";
    }
    else if (choice == 3)
    {
        //outprocess
        query = "INSERT INTO ScoreCard VALUES (" + std::to_string(gamePlayBalls) + "," + std::to_string(gamePlayOvers) + "," + std::to_string(404) + "," + std::to_string(gamePlayMatchId) + ",\"" + batters[0].first + "\",\"" + bowler.first + "\")";
        gamePlayOut += 1;

        if (gamePlayOutBound == gamePlayOut)
        {
            //constraints
            swap(teams.first, teams.second);
            swapOrder();
        }
        setBatters();
    }
    else if (choice == 4)
    {
        int runsScored;
        print("Enter The Runs Scored : ", 0);
        std::cin >> runsScored;
        getchar();

        query = "INSERT INTO ScoreCard VALUES (" + std::to_string(gamePlayBalls) + "," + std::to_string(gamePlayOvers) + "," + std::to_string(runsScored) + "," + std::to_string(gamePlayMatchId) + ",\"" + batters[0].first + "\",\"" + bowler.first + "\")";

        gamePlayRuns += runsScored;

        if (runsScored % 2 != 0)
        {
            swap(batters[0], batters[1]);
        }
    }
    else
    {
        return;
    }

    try
    {
        std::cout << query << "\n";
        getchar();
        if (!execute_query(query))
        {
            throw 0;
        }
    }
    catch (int e)
    {
        print("This Operation has issues", 1);
    }

    if (gamePlayBalls == 6)
    {
        setBowler();
        swap(batters[0], batters[1]);
        gamePlayOvers+=1;
        gamePlayBalls = 1;
    }
    else
    {
        gamePlayBalls += 1;
    }
    gameDisplay();
}
void gamePlay::setBatters(int toBeSet)
{   

    if (isBatting == 'A')
    {
        for (int i = 0; i < toBeSet; i++)
        {
            batters[i].first = boTeamA.front().first;
            batters[i].second = boTeamA.front().second;
            boTeamA.pop();
        }
    }
    else
    {
        for (int i = 0; i < toBeSet; i++)
        {
            batters[i].first = boTeamB.front().first;
            batters[i].second = boTeamB.front().second;
            boTeamB.pop();
        }
    }

    return;
}

void gamePlay::setBowler(void)
{
    print("Choose Player ID from Below Who Will be Bowling", 2);
    viewTeamOrder(bowlingTeam());

    print("Enter Player Name : ", 0);
    std::getline(std::cin, bowler.first);

    print("Enter Bowler ID : ", 0);
    std::cin >> bowler.second;
}

void gamePlay::viewTeamOrder(std::queue<std::pair<std::string, int>> team)
{
    // std::cout << "Test Running\n";
    // std::cout << team.size() << "\n";
    // std::cout << boTeamA.size() << "\n";
    // std::cout << boTeamB.size() << "\n";

    for (int i = 1; team.empty() != true; i++)
    {
        print(std::to_string(i) + " : " + team.front().first + std::string(", ") + std::to_string(team.front().second) + std::string("\n"));
        //std::cout<<team.front().first<<", "<<team.front().second<<"\n";
        team.pop();
    }

    // std::cout << "Test Running After\n";
    // std::cout << team.size() << "\n";
    // std::cout << boTeamA.size() << "\n";
    // std::cout << boTeamB.size() << "\n";

    getchar();
}
void gamePlay::startMatch()
{
    Matches matchInfo;
    Player playerInfo;
    Team teamInfo;

    print("Welcome To Live Match Managment Section", 2);
    print("Enter ID of Match : ", 0);
    std::cin >> gamePlayMatchId;
    getchar();

    if (!matchInfo.matchExists(gamePlayMatchId)) //Check if Match ID Exists in Record
    {
        return;
    }

    matchInfo.setTeams(teams, gamePlayMatchId); //set teams pair declared above

    // BATTING ORDER OF TEAM'S Setup Begins
    print("Set Batting Order Of TeamA : ", 2);

    playerInfo.displayAllPlayers(teams.first);

    playerInfo.setupBattingOrder(boTeamA);

    //Create View Team Function in Teams;
    viewTeamOrder(boTeamA);

    print("Press Any Key to Continue Setting Up TeamB Order", 2);
    getchar();
    system("clear");

    print("Set Batting Order Of TeamB : ", 2);

    playerInfo.displayAllPlayers(teams.second);

    playerInfo.setupBattingOrder(boTeamB);

    //Create View Team Function in Teams;
    viewTeamOrder(boTeamB);

    print("Press Any Key to Continue With Toss Result", 2);
    getchar();
    system("clear");

    // BATTING ORDER OF TEAM'S Setup Ends

    //Batting Order Of Team whichs bats first Based on Toss

    int choice;

    print("Select the Team That will Bat First : ");

    print("1. " + teams.first, 1);
    print("2. " + teams.second, 1);

    print("Select Your Choice : ", 0);
    std::cin >> choice;
    getchar();

    if (choice == 2)
    {
        swap(teams.first, teams.second);
        swapOrder();
    }

    //Inital Setup When Game Begins
    setBatters(2);
    setBowler();

    gameDisplay();

    gamePlayOvers = 1;
    gamePlayBalls = 1;
}

std::queue<std::pair<std::string, int>> gamePlay::battingTeam(void)
{
    if (isBatting == 'A')
    {
        return boTeamA;
    }
    return boTeamB;
}
std::queue<std::pair<std::string, int>> gamePlay::bowlingTeam(void)
{
    if (isBatting == 'A')
    {
        return boTeamB;
    }
    return boTeamA;
}
void gamePlay::swapOrder(void)
{   
    std::swap(isBatting, isBowling);
}