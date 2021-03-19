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
    json infoJson = getInfo();
    game->ant_type_ = (infoJson["ant_type"] == 1 ? KARGAR : SARBAZ);
    game->map_width_ = infoJson["map_width"];
    game->map_height_ = infoJson["map_height"];
    game->base_x_ = infoJson["base_x"];
    game->base_y_ = infoJson["base_y"];
    game->health_kargar_ = infoJson["health_kargar"];
    game->health_sarbaaz_ = infoJson["health_sarbaaz"];
    game->attack_distance_ = infoJson["attack_distance"];
    game->generate_kargar_ = infoJson["generate_kargar"];
    game->generate_sarbaaz_ = infoJson["generate_sarbaaz"];
    game->rate_death_resource_ = infoJson["rate_death_resource"];
}