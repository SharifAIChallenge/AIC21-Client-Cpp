#include <Utility/Logger.h>
#include "Game.h"
#include "enums.h"


Game::Game(EventQueue &event_queue) : event_queue_(event_queue) {
}

Game::Game(const Game& game) : event_queue_(game.event_queue_) {
    ant_type_ = game.getAntType();
    map_width_ = game.getMapWidth();
    map_height_ = game.getMapHeight();
    base_x_ = game.getBaseX();
    base_y_ = game.getBaseY();
    health_queen_ = game.getHealthQueen();
    health_scorpion_ = game.getHealthScorpion();
    attack_distance_ = game.getAttackDistance();
    generate_queen_ = game.getGenerateQueen();
    generate_scorpion_ = game.getGenerateScorpion();
    rate_death_resource_ = game.getRateDeathResource();
    view_distance_ = game.getViewDistance();

    for (const Base* base: game.getBases()) {
        bases_.push_back(new Base(base->getX(), base->getY()));
    }
}

const Ant* Game::getAnt() const {
    return ant_;
}

AntType Game::getAntType() const {
    return ant_type_;
}

const ChatBox* Game::getChatBox() const {
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

int Game::getHealthQueen() const {
    return health_queen_;
}

int Game::getHealthScorpion() const {
    return health_scorpion_;
}

int Game::getAttackDistance() const {
    return attack_distance_;
}

int Game::getGenerateQueen() const {
    return generate_queen_;
}

int Game::getGenerateScorpion() const {
    return generate_scorpion_;
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
    health_queen_ = infoJson["health_kargar"];
    health_scorpion_ = infoJson["health_sarbaaz"];
    attack_distance_ = infoJson["attack_distance"];
    generate_queen_ = infoJson["generate_kargar"];
    generate_scorpion_ = infoJson["generate_sarbaaz"];
    rate_death_resource_ = infoJson["rate_death_resource"];
    view_distance_ = infoJson["view_distance"];

    for (json baseJson: infoJson["bases"]) {
        bases_.push_back(new Base(baseJson["x"], baseJson["y"]));
    }
}

void Game::setCurrentState(CurrentStateMessage *currentStateMessage) {
    json infoJson = currentStateMessage->getInfo();

    //chat box
    Logger::Get(LogLevel_TRACE) << "creating chat box" << endl;
    vector<const Chat*> allChats;
    for (json chatJson : infoJson["chat_box"]) {
        allChats.push_back(new Chat(chatJson["text"], chatJson["turn"]));
    }
    chat_box_ = new ChatBox(allChats);

    //map
    Logger::Get(LogLevel_TRACE) << "creating map" << endl;
    vector<vector<Cell*>> mapCells(map_width_, vector<Cell*>(map_height_));
    for (json cellJson : infoJson["around_cells"]) {
        int x = cellJson["cell_x"];
        int y = cellJson["cell_y"];
        mapCells[x][y] = new Cell(EnumUtils::getCellTypeByInt(cellJson["cell_type"]), x, y,
                new Resource(EnumUtils::getResourceTypeByInt(cellJson["resource_type"]), cellJson["resource_value"]));
        for (json antJson : cellJson["ants"]) {
            mapCells[x][y]->addAntToCell(
                    new Ant(EnumUtils::getAntTypeByInt(antJson["ant_type"]),
                            EnumUtils::getAntTeamByInt(antJson["ant_team"]),x, y));
        }
    }

    Logger::Get(LogLevel_TRACE) << "creating map instance" << endl;
    Map* map = new Map(mapCells, map_width_, map_height_, attack_distance_,
            infoJson["current_x"], infoJson["current_y"]);

    //ant
    Logger::Get(LogLevel_TRACE) << "creating ant" << endl;
    ant_ = new Ant(ant_type_, ALLY, view_distance_, attack_distance_, *map,
            new Resource(EnumUtils::getResourceTypeByInt(infoJson["current_resource_type"]),
                    infoJson["current_resource_value"]),
            infoJson["current_x"], infoJson["current_y"], infoJson["health"]);

    //attacks
    Logger::Get(LogLevel_TRACE) << "creating attacks" << endl;
    for (json attackJson : infoJson["attacks"]) {
        attacks.push_back(new Attack(attackJson["attacker_col"], attackJson["attacker_row"],
                attackJson["defender_col"], attackJson["defender_row"],
                attackJson["is_attacker_enemy"]));
    }
}

Game::~Game() {
    delete chat_box_;
    delete ant_;
    for (const Attack* attack: attacks) {
        delete attack;
    }
    // bases get copied to new game before destruction
    for (const Base* base: bases_) {
        delete base;
    }
}

int Game::getViewDistance() const {
    return view_distance_;
}

const vector<const Attack *> &Game::getAttacks() const {
    return attacks;
}

const vector<const Base *> &Game::getBases() const {
    return bases_;
}
