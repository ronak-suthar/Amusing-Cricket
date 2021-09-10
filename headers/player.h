#ifndef PLAYER_H
#define PLAYER_H

#include "database.h"

class Player:public database{
    std::string Name;
    std::string Role;
    std::string TeamName;
    int ID;

    public:
    Player(std::string="Dummy",std::string="Dummy",std::string="Dummy",int=0);
    void getData(void);
    void insertData(void);
    void updateData(void);
    void removeData(void);
    void viewData(void);
};
#endif