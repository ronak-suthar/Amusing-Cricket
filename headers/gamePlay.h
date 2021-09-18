#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "database.h"

class gamePlay:public database{
    int gamePlayBalls,gamePlayOvers,gamePlayBatsmanId,gamePlayBowlerId,gamePlayRuns,gamePlayMatchId;

    public:

    void startMatch(void);
};

#endif