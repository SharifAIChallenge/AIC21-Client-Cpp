#include "Game.h"

vector<Node> Game::getNodesByOwner(Owner owner) {
    vector<Node> out;
    for(Node node : graph_.getNodes())
        if(node.getOwner() == owner)
            out.push_back(node);
    return out;
}

vector<Node> Game::getNodes() {
    return graph_.getNodes();
}

Node* Game::getNodeById(string id) {
    for(Node node : graph_.getNodes())
        if(node.getId() == id)
            return &node;
    return NULL;
}

int Game::getMyScore() const {
    return myScore_;
}

int Game::getEnemyScore() const {
    return enemyScore_;
}

int Game::getTurn() const {
    return turn_;
}

void Game::attack(Node myNode, Node enemyNode) {
    return;
}

void Game::movePower(Node myNode, Node enemyNode) {
    return;
}