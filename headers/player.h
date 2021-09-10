#ifndef PLAYER_H
#define PLAYER_H
#include<string>

class Player{
    std::string Name;
    std::string Role;
    std::string TeamName;
    int ID;

    public:
    Player(std::string="Dummy",std::string="Dummy",std::string="Dummy",int=0);
    void getData(void);
    const std::string insertData(void);
    void updateData(int);
    void removeData(int);
    void viewData(int);

};
#endif