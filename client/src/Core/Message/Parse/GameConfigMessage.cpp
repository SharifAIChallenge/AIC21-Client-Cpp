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

void GameConfigMessage::updateGame(Game *game) {
    game->ant_type_ = (m_root_["ant_type"] == 1 ? KARGAR : SARBAZ);
    game->map_width_ = m_root_["map_width"];
    game->map_height_ = m_root_["map_height"];
    game->base_x_ = m_root_["base_x"];
    game->base_y_ = m_root_["base_y"];
    game->health_kargar_ = m_root_["health_kargar"];
    game->health_sarbaaz_ = m_root_["health_sarbaaz"];
    game->attack_distance_ = m_root_["attack_distance"];
    game->generate_kargar_ = m_root_["generate_kargar"];
    game->generate_sarbaaz_ = m_root_["generate_sarbaaz"];
    game->rate_death_resource_ = m_root_["rate_death_resource"];
}