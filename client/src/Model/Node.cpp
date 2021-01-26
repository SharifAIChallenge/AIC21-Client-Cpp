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

int Node::getValue() const {
    return value_;
}

void Node::setValue(int value) {
    value_ = value;
}

vector<Node> Node::getNeighbours() const {
    return neighbours_;
}

void Node::setNeighbours(vector<Node> neighbours) {
    neighbours_ = neighbours;
}

vector<Node> Node::getNeighboursByOwner(Owner owner) {
    vector<Node> out;
    for(Node neighbour : neighbours_)
        if(neighbour.getOwner() == owner)
            out.push_back(neighbour);
    return out;
}