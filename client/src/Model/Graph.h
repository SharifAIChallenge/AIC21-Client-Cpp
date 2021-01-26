#ifndef AIC21_CLIENT_CPP_GRAPH_H
#define AIC21_CLIENT_CPP_GRAPH_H

#include "Node.h"


class Graph {

public:
    Graph() = default;

    ~Graph() = default;

    void addNode(Node node);

    vector<Node> getNodes() const;

private:
    vector<Node> nodes_;

};


#endif //AIC21_CLIENT_CPP_GRAPH_H
