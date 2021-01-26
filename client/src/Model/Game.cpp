#include "Game.h"

static Owner Game::getPlayerByTurn(int turn) {
    if(turn == 0)
        return Owner.ME;
    return Owner.ENEMY;
}

void Game::declareWinner(int winner) {
    winner_ = winner;

}

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

int Game::getWinner() const {
    return winner_;
}

void Game::nextTurn() const {
    // TODO : check for winner
    turn_ = (turn_+1)%2;
};

Owner Game::getCurrentPlayer() const {
    return getPlayerByTurn(turn_);
};

Owner Game::getOtherPlayer() const {
    return getPlayerByTurn((turn_+1)%2);
}

void Game::attack(Node src, Node dst) {
    Owner currentPlayer = getCurrentPlayer();
    if(src.getOwner() != currentPlayer || dst.getOwner() == currentPlayer || dst.getOwner() == Owner.FREE)
        // TODO : throw exception
        return;
    if(src.getValue() > dst.getValue())
        dst.setOwner(currentPlayer);
    else
        declareWinner((turn_+1)%2);
    // TODO : Score system
    nextTurn();
}

void Game::transitValue(Node src, Node dst) {
    Owner currentPlayer = getCurrentPlayer();
    if(src.getOwner() != currentPlayer || dst.getOwner() != currentPlayer || !src.isAdjacentTo(dst))
        // TODO : throw exception
        return;
    src.setValue(src.getValue()-1);
    dst.setValue(dst.getValue()+1);
    // TODO : Score system
    nextTurn();
}

void Game::conquer(Node src, Node dst) {
    Owner currentPlayer = getCurrentPlayer();
    if(src.getOwner() != currentPlayer || dst.getOwner() != Owner.FREE)
        // TODO : throw exception
        return;
    src.setValue(src.getValue()-1);
    dst.setOwner(currentPlayer);
    dst.setValue(1);
    // TODO : Score system
    nextTurn();
}