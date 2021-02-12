#ifndef AIC21_CLIENT_CPP_GAME_H
#define AIC21_CLIENT_CPP_GAME_H

#include "Models/enums.h"
#include "Models/Ant.h"
#include "Models/ChatBox.h"
#include "Models/Game.h"
#include "Core/Message/Parse/GameConfigMessage.h"


class Game {

    private:

    Ant ant_;
    ChatBox chat_box_;
    AntType ant_type_;
    int map_width_;
    int map_height_;
    int base_x_;
    int base_y_;
    int health_kargar_;
    int health_sarbaaz_;
    int attack_distance_;
    int generate_kargar_;
    int generate_sarbaaz_;
    int rate_death_resource_;
    Ant initialAntState(CurrentStateMessage stateMessage);


    public:

    Game() = default;
    Game(const Game&);
    void setCurrentState(CurrentStateMessage stateMessage);
    Ant getAnt() const;
    AntType getAntType() const;
    ChatBox getChatBox() const;
    int getMapWidth() const;
    int getMapHeight() const;
    int getBaseX() const;
    int getBaseY() const;
    int getHealthKargar() const;
    int getHealthSarbaaz() const;
    int getAttackDistance() const;
    int getGenerateKargar() const;
    int getGenerateSarbaaz() const;
    int getRateDeathResource() const;

    friend class GameConfigMessage;
};

#endif //AIC21_CLIENT_CPP_GAME_H