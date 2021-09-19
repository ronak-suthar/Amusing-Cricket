#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "database.h"
#include <queue>
#include <utility>
#include <vector>

class gamePlay:public database{
    int gamePlayBalls,gamePlayOvers,gamePlayBatsmanId,gamePlayBowlerId,gamePlayRuns,gamePlayMatchId;
    int gamePlayOut,gamePlayOverBound,gamePlayOutBound;
    char isBatting;
    char isBowling;

    std::queue<std::pair<std::string, int>> boTeamA, boTeamB; //Batting Order Team Order

    std::pair<std::string, std::string> teams; //Team A and Team B Name

    //std::queue<std::pair<std::string, int>>& toBat,toBowl;
    //above have refrence to teams batting order which is either batting or bowling

    std::vector<std::pair<std::string, int>> batters;
    //array of two batters who are batting

    std::pair<std::string, int> bowler;
    public:

    gamePlay(void);
    void startMatch(void);
    void setBatters(int=1);
    void setBowler(void);
    void viewTeamOrder(std::queue<std::pair<std::string, int>>);

    void setBounds();
    void gameDisplay();
    void getGameStatus();

    std::queue<std::pair<std::string, int>> battingTeam();
    std::queue<std::pair<std::string, int>> bowlingTeam();
    void swapOrder(void);
};


#endif