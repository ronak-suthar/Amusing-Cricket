#include"../headers/gamePlay.h"
#include"../headers/menu.h"
#include"../headers/Matches.h"
#include"../headers/player.h"
#include"../headers/Team.h"
#include<iostream>
#include<queue>
#include<utility>

void gamePlay::startMatch(){
    Matches matchInfo;Player playerInfo;Team teamInfo;

    print("Welcome To Live Match Managment Section",2);
    print("Enter ID of Match : ",0);
    std::cin>>gamePlayMatchId;
    getchar();

    if(!matchInfo.matchExists(gamePlayMatchId)){
        return;
    }

    std::queue<std::pair<std::string,int>> boTeamA,boTeamB;//Batting Order Team Order

    std::pair<std::string,std::string> teams;//Team A and Team B Name

    matchInfo.setTeams(teams,gamePlayMatchId);

    print("Set Batting Order Of TeamA : ",2);

    playerInfo.displayAllPlayers(teams.first);

    playerInfo.setupBattingOrder(boTeamA);

    //Create View Team Function in Teams;
    for(int i=1;boTeamA.empty()!=true;i++){
        print(std::to_string(i)+" : "+boTeamA.front().first + std::string(", ") + std::to_string(boTeamA.front().second) + std::string("\n"));
        //std::cout<<boTeamA.front().first<<", "<<boTeamA.front().second<<"\n";
        boTeamA.pop();
    }

    print("Press Any Key to Continue Setting Up TeamB Order",2);
    getchar();
    system("clear");

    print("Set Batting Order Of TeamB : ",2);

    playerInfo.displayAllPlayers(teams.second);

    playerInfo.setupBattingOrder(boTeamB);

    //Create View Team Function in Teams;
    for(int i=1;boTeamB.empty()!=true;i++){
        print(std::to_string(i)+" : "+boTeamB.front().first + std::string(", ") + std::to_string(boTeamB.front().second) + std::string("\n"));
        //std::cout<<boTeamB.front().first<<", "<<boTeamB.front().second<<"\n";
        boTeamB.pop();
    }

    

}