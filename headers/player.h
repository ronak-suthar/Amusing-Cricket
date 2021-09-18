#ifndef PLAYER_H
#define PLAYER_H

#include "database.h"
#include <queue>
#include <utility>

class Player:public database{
    std::string playerName;
    std::string playerRole;
    std::string playerTeamName;
    int ID;

    public:
    Player(std::string="Dummy",std::string="Dummy",std::string="Dummy",int=0);
    void getData(void);
    void insertData(void);
    void updateData(void);
    void removeData(void);
    void viewData(void);

    std::string getPlayerName(int);
    void displayAllPlayers(std::string&);
    void setupBattingOrder(std::queue<std::pair<std::string,int>>&);
};
#endif