#ifndef AIC21_CLIENT_CPP_GAME_CONFIG_MESSAGE_H
#define AIC21_CLIENT_CPP_GAME_CONFIG_MESSAGE_H

#include "Core/Message/Message.h"
#include "ParseError.h"
#include "Models/Game.h"
#include "Models/enums.h"
#include <vector>
using namespace std;


class GameConfigMessage final : public Message {

public:

    explicit GameConfigMessage(const json &root);
    explicit GameConfigMessage(const string &json_form);
    void updateGame(Game* game);


private:

    int getMapWidth();
    int getMapHeight();
    AntType getAntType();
    int getBaseX();
    int getBaseY();
    int getHealthKargar();
    int getHealthSarbaaz();
    int getAttackDistance();
    int getGenerateKargar();
    int getGenerateSarbaaz();
    int getRateDeathResource();

};

#endif // AIC21_CLIENT_CPP_GAME_CONFIG_MESSAGE_H
