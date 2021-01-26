#ifndef AIC21_CLIENT_CPP_NODE_H
#define AIC21_CLIENT_CPP_NODE_H

#include <string>
#include <vector>
#include "enums.h"


class Node {

public:
    Node() = default;

    ~Node() = default;

    string getId() const;

    void setId(string id);

    Owner getOwner() const;

    void setOwner(Owner owner);

    int getValue() const;

    void setValue(int value);

    vector<Node> getNeighbours() const;

    void setNeighbours(vector<Node> neighbours);

    vector<Node> getNeighboursByOwner(Owner owner);

private:
    string id_;
    Owner owner_;
    int value_;
    vector<Node> neighbours_;
};


#endif //AIC21_CLIENT_CPP_NODE_H
