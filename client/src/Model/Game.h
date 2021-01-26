#ifndef AIC21_CLIENT_CPP_GAME_H
#define AIC21_CLIENT_CPP_GAME_H

#include "Graph.h"
#include "enums.h"

class Game {

public:
    Game() = default;

    ~Game() = default;

    vector<Node> getNodesByOwner(Owner owner);

    vector<Node> getNodes();

    Node* getNodeById(string id);

    int getMyScore() const;

    int getEnemyScore() const;

    int getTurn() const;

    void attack(Node myNode, Node enemyNode);

    void movePower(Node myNode, Node enemyNode);

private:
    Graph graph_;
    int myScore_;
    int enemyScore_;
    int turn_;
};


#endif //AIC21_CLIENT_CPP_GAME_H