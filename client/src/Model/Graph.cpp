#include "Graph.h"

void Node::addNode(Node node) {
    return nodes_.push_back(node);
}

vector<Node> Node::getNodes() const{
    return nodes_;
}
