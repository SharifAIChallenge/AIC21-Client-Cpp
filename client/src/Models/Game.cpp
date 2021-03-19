#include "Game.h"
#include "enums.h"

// Ant Game::initialAntState(CurrentStateMessage stateMessage) {
//     vector<vector<Cell>> cells = stateMessage.getVisibleCells(map_height_, map_width_);
//     Map map(
//         cells,
//         map_width_,
//         map_height_,
//         attack_distance_,
//         stateMessage.getCurrentX(),
//         stateMessage.getCurrentY()
//     );
//     return Ant(ant_type_, ALLY, attack_distance_, map, stateMessage);
// }

Game::Game(EventQueue &event_queue) : event_queue_(event_queue) {
}

Game::Game(const Game& game) : event_queue_(game.event_queue_) {
    ant_type_ = game.getAntType();
    map_width_ = game.getMapWidth();
    map_height_ = game.getMapHeight();
    base_x_ = game.getBaseX();
    base_y_ = game.getBaseY();
    health_kargar_ = game.getHealthKargar();
    health_sarbaaz_ = game.getHealthSarbaaz();
    attack_distance_ = game.getAttackDistance();
    generate_kargar_ = game.getGenerateKargar();
    generate_sarbaaz_ = game.getGenerateSarbaaz();
    rate_death_resource_ = game.getRateDeathResource();
}

Ant Game::getAnt() const {
    return ant_;
}

AntType Game::getAntType() const {
    return ant_type_;
}

ChatBox Game::getChatBox() const {
    return chat_box_;
}

int Game::getMapWidth() const {
    return map_width_;
}

int Game::getMapHeight() const {
    return map_height_;
}

int Game::getBaseX() const {
    return base_x_;
}

int Game::getBaseY() const {
    return base_y_;
}

int Game::getHealthKargar() const {
    return health_kargar_;
}

int Game::getHealthSarbaaz() const {
    return health_sarbaaz_;
}

int Game::getAttackDistance() const {
    return attack_distance_;
}

int Game::getGenerateKargar() const {
    return generate_kargar_;
}

int Game::getGenerateSarbaaz() const {
    return generate_sarbaaz_;
}

int Game::getRateDeathResource() const {
    return rate_death_resource_;
}

void Game::initGameConfig(GameConfigMessage *initMessage) {
    json infoJson = initMessage->getInfo();
    ant_type_ = (infoJson["ant_type"] == 1 ? KARGAR : SARBAZ);
    map_width_ = infoJson["map_width"];
    map_height_ = infoJson["map_height"];
    base_x_ = infoJson["base_x"];
    base_y_ = infoJson["base_y"];
    health_kargar_ = infoJson["health_kargar"];
    health_sarbaaz_ = infoJson["health_sarbaaz"];
    attack_distance_ = infoJson["attack_distance"];
    generate_kargar_ = infoJson["generate_kargar"];
    generate_sarbaaz_ = infoJson["generate_sarbaaz"];
    rate_death_resource_ = infoJson["rate_death_resource"];
}

void Game::setCurrentState(CurrentStateMessage *currentStateMessage) {

}
