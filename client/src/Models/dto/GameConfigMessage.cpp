#include "GameConfigMessage.h"

int GameConfigMessage::getMapWidth() {
    return map_width;
}

int GameConfigMessage::getMapHeight() {
    return map_height;
}

AntType GameConfigMessage::getAntType() {
    return (ant_type == 1)? KARGAR : SARBAZ;
}

int GameConfigMessage::getBaseX() {
    return base_x;
}

int GameConfigMessage::getBaseY() {
    return base_y;
}

int GameConfigMessage::getHealthKargar() {
    return health_kargar;
}

int GameConfigMessage::getHealthSarbaaz() {
    return health_sarbaaz;
}

int GameConfigMessage::getAttackDistance() {
    return attack_distance;
}

int GameConfigMessage::getGenerateKargar() {
    return generate_kargar;
}

int GameConfigMessage::getGenerateSarbaaz() {
    return generate_sarbaaz;
}

int GameConfigMessage::getRateDeathResource() {
    return rate_death_resource;
}
