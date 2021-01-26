#include "Node.h"

int Node::getId() const {
    return id_;
}

void Node::setId(string id) {
    return id_ = id;
}

Owner Node::getOwner() const {
    return owner_;
}

void Node::setOwner(Owner owner) {
    owner_ = owner;
}

int Node::getPower() const {
    return power_;
}

void Node::setPower(int power) {
    power_ = power;
}

vector<Node> Node::getNeighbours() const {
    return neighbours_;
}

void Node::setNeighbours(vector<Node> neighbours) {
    neighbours_ = neighbours;
}