#ifndef MATCHES_H
#define MATCHES_H
#include "database.h"

class Matches : public database{
    std::string matchTeamNameA;
    std::string matchTeamNameB;
    std::string matchDate;
    std::string matchType;
    int matchId;

    public:

    Matches(std::string="Dummy",std::string="Dummy",std::string="Dummy",std::string="Dummy",int=0);
    void getData(void);
    void insertData(void);
    void updateData(void);
    void removeData(void);
    void viewData(void);

    bool matchExists(int);
    void setTeams(std::pair<std::string,std::string>&,int);

};

#endif