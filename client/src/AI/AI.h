#ifndef AIC21_CLIENT_CPP_AI_H
#define AIC21_CLIENT_CPP_AI_H

#include "Models/Game.h"
#include "Models/Answer.h"

class AI {
public:
    Answer* turn(Game *game);

private:
    static int agent_id;    //Random generated Id for optional use
};

#endif // AIC21_CLIENT_CPP_AI_H
