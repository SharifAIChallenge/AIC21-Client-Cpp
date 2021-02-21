#ifndef AIC21_CLIENT_CPP_GAMECONFIGMESSAGE_H
#define AIC21_CLIENT_CPP_GAMECONFIGMESSAGE_H

#include "Models/enums.h"


class GameConfigMessage {

    public:

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


    private:

    int map_width;
    int map_height;
    int ant_type;
    int base_x;
    int base_y;
    int health_kargar;
    int health_sarbaaz;
    int attack_distance;
    int generate_kargar;
    int generate_sarbaaz;
    int rate_death_resource;

};

#endif // AIC21_CLIENT_CPP_GAMECONFIGMESSAGE_H