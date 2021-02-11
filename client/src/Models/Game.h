#ifndef AIC21_CLIENT_CPP_GAME_H
#define AIC21_CLIENT_CPP_GAME_H

#include "enums.h"
#include "Ant.h"
#include "ChatBox.h"
#include "Game.h"
#include "GameConfigMessage.h"


class Game {

    private:

    Ant ant;
    ChatBox chatBox;
    AntType antType;
    int mapWidth;
    int mapHeight;
    int baseX;
    int baseY;
    int healthKargar;
    int healthSarbaaz;
    int attackDistance;
    int generateKargar;
    int generateSarbaaz;
    int rateDeathResource;
    Ant initialAntState(CurrentStateMessage stateMessage);


    public:

    Game();
    Game(const Game&);
    void initGameConfig(GameConfigMessage configMessage);
    void setCurrentState(CurrentStateMessage stateMessage);
    Ant getAnt();
    AntType getAntType();
    ChatBox getChatBox();
    int getMapWidth();
    int getMapHeight();
    int getBaseX();
    int getBaseY();
    int getHealthKargar();
    int getHealthSarbaaz();
    int getAttackDistance();
    int getGenerateKargar();
    int getGenerateSarbaaz();
    int getRateDeathResource();
};

#endif //AIC21_CLIENT_CPP_GAME_H