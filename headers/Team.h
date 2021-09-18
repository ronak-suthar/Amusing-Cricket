#ifndef TEAM_H
#define TEAM_H

#include"database.h"

class Team:public database{
    std::string Name;
    std::string Board;
    std::string Email;

    public:
    
    Team(std::string="Dummy",std::string="Dummy",std::string="dummy");

    void getData(void);
    void insertData(void);
    void updateData(void);
    void removeData(void);
    void viewData(void);

};

#endif