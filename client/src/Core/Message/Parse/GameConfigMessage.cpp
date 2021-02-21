#include "Utility/Logger.h"
#include "Utility/Utility.h"
#include "Core/Message/Parse/GameConfigMessage.h"

using namespace std;

GameConfigMessage::GameConfigMessage(const json &root) : Message(root) {
    if (getType() != "3")
        throw ParseError("Invalid game config message");
}

GameConfigMessage::GameConfigMessage(const string &json_form) : Message(json_form) {
    if (getType() != "3")
        throw ParseError("Invalid game config message");
}

int GameConfigMessage::getMapWidth() {
    return m_root_["map_width"];
}

int GameConfigMessage::getMapHeight() {
    return m_root_["map_height"];
}

AntType GameConfigMessage::getAntType() {
    int antType = m_root_["ant_type"];
    return (antType == 1)? KARGAR : SARBAZ;
}

int GameConfigMessage::getBaseX() {
    return m_root_["base_x"];
}

int GameConfigMessage::getBaseY() {
    return m_root_["base_y"];
}

int GameConfigMessage::getHealthKargar() {
    return m_root_["health_kargar"];
}

int GameConfigMessage::getHealthSarbaaz() {
    return m_root_["health_sarbaaz"];
}

int GameConfigMessage::getAttackDistance() {
    return m_root_["attack_distance"];
}

int GameConfigMessage::getGenerateKargar() {
    return m_root_["generate_kargar"];
}

int GameConfigMessage::getGenerateSarbaaz() {
    return m_root_["generate_sarbaaz"];
}

int GameConfigMessage::getRateDeathResource() {
    return m_root_["rate_death_resource"];
}

void GameConfigMessage::updateGame(Game *game) {
    game->ant_type_ = getAntType();
    game->map_width_ = getMapWidth();
    game->map_height_ = getMapHeight();
    game->base_x_ = getBaseX();
    game->base_y_ = getBaseY();
    game->health_kargar_ = getHealthKargar();
    game->health_sarbaaz_ = getHealthSarbaaz();
    game->attack_distance_ = getAttackDistance();
    game->generate_kargar_ = getGenerateKargar();
    game->generate_sarbaaz_ = getGenerateSarbaaz();
    game->rate_death_resource_ = getRateDeathResource();
}