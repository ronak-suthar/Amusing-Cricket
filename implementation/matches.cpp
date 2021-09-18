#include "../headers/Matches.h"
#include "../headers/menu.h"
#include <iostream>
#include <iomanip>

Matches::Matches(std::string a, std::string b, std::string date, std::string type, int id)
{
    matchTeamNameA = a;
    matchTeamNameB = b;
    matchDate = date;
    matchType = type;
    matchId = id;
}

void Matches::getData(void)
{
    print("Kindly Provide Below Information to Set Up Match", 2);

    print("1.Enter First Teams Name : ", 0);
    std::getline(std::cin, matchTeamNameA);

    print("2.Enter Second Teams Name : ", 0);
    std::getline(std::cin, matchTeamNameB);

    print("3.Enter Match Date in YYYY-MM-DD : ", 0);
    std::getline(std::cin, matchDate);

    int choice;

    print("Select Match Type : ", 1);

    print("1.T20 Match ", 1);
    print("2.Test Match", 1);
    print("3.ODI Match ", 1);

    print("Enter Choice of Match Type : ", 0);
    std::cin >> choice;
    getchar();

    if (choice == 1)
    {
        matchType = "T20";
    }
    else if (choice == 2)
    {
        matchType = "Test";
    }
    else if (choice == 3)
    {
        matchType = "ODI";
    }
    else
    {
        print("Wrong Choice Press Any Key To Continue", 2);
    }

    print("Enter Match Unique ID : ", 0);
    std::cin >> matchId;
    getchar();
}

void Matches::insertData(void)
{
    std::string query = "INSERT INTO Matches VALUES(\"" + matchTeamNameA + "\",\"" + matchTeamNameB + "\",\"" + matchDate + "\",\"" + matchType + "\"," + std::to_string(matchId) + ")";

    if (execute_query(query) && mysql_affected_rows(conn) != 0)
    {
        print("Transaction Successfull");
        print("Press Any key to go back to menu");
    }
    else if (mysql_affected_rows(conn) == 0)
    {
        print("Records Already doesn't Exists for given ID");
    }
    else
    {
        print("There is Some Issue with your transactions");
    }
}

void Matches::updateData()
{
}

void Matches::removeData()
{
    print("This Section Removes Data Of a Match in Record", 1);
    print("Note : All Data Corresponding to This Match ID will also be removed from ScoreCard Record", 1);

    int removematchId;
    print("Enter Match ID whose Record You Want To Remove From Record : ");
    std::cin >> removematchId;
    getchar();

    std::string query = "DELETE FROM ScoreCard WHERE matchId=" + std::to_string(removematchId);

    if (!execute_query(query))
    {
        print("There is Some Issue with Your Request", 1);
        return;
    }

    query = "DELETE FROM Matches WHERE matchId=" + std::to_string(removematchId);

    if (execute_query(query))
    {
        print("Transaction Successfull");
    }
    else
    {
        print("There is Some Issue with Your Request", 1);
    }
}
void Matches::viewData()
{
    std::string query = "SELECT * FROM Matches";

    if (execute_query(query))
    {
        res = mysql_use_result(conn);

        print("Below Are Matches in Record : ", 2);

        std::cout << std::string(95, '-');
        std::cout << "\n";

        std::cout << std::setw(22) << std::left << "| Team A";
        std::cout << std::setw(22) << std::left << "| Team B";
        std::cout << std::setw(17) << std::left << "| Date";
        std::cout << std::setw(17) << std::left << "| Match Type";
        std::cout << std::setw(12) << std::left << "| Match ID|\n";

        std::cout << std::string(95, '-');
        std::cout << "\n";

        while ((this->row = mysql_fetch_row(this->res)) != NULL)
        {
            std::cout << "| " << std::setw(20) << std::left << row[0];
            std::cout << "| " << std::setw(20) << std::left << row[1];
            std::cout << "| " << std::setw(15) << std::left << row[2];
            std::cout << "| " << std::setw(15) << std::left << row[3];
            std::cout << "| " << std::setw(10) << std::left << row[4];
            std::cout << "\n";
            std::cout << std::string(95, '-');
            std::cout << "\n";
        }

        std::cout << std::string(95, '-');
        std::cout << "\n";

        mysql_free_result(res);
    }
    else
    {
        print("There is Some Issue with your transactions");
    }

    print("Press Any Key To Continue", 2);
}

bool Matches::matchExists(int id)
{
    std::string query = "SELECT COUNT(MatchID) FROM Matches WHERE MatchID=" + std::to_string(id);

    try
    {
        if (!execute_query(query))
        {
            throw 0; //Issues With Query
        }

        res = mysql_use_result(conn);

        row = mysql_fetch_row(res);

        if (row != NULL)
        {
            if (atoi(row[0]) == 0)
            {
                print("Match ID Does'nt Exists in Record", 1);
                mysql_free_result(res);
                return false;
            }
            else{
                mysql_free_result(res);
                return true;
            }
        }
        else
        {
            throw 0;
        }
    }
    catch (const int e)
    {
        print("This Operation has issues", 1);
        return false;
    }

    return true;
}

void Matches::setTeams(std::pair<std::string, std::string> &data, int id)
{
    std::string query = "SELECT TeamA,TeamB FROM Matches WHERE MatchID = " + std::to_string(id);

    try
    {
        if (!execute_query(query))
        {
            throw 0; //Issues With Query
        }

        res = mysql_use_result(conn);

        row = mysql_fetch_row(res);

        if (row != NULL)
        {
            data.first = row[0];
            data.second = row[1];
            mysql_free_result(res);
        }
        else
        {
            throw 0;
        }
    }
    catch (int e)
    {
        print("This Operation has issues", 1);
    }
}