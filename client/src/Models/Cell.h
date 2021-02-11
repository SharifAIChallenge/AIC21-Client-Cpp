#ifndef AIC21_CLIENT_CPP_CELL_H
#define AIC21_CLIENT_CPP_CELL_H

#include <vector>
#include "enums.h"
#include "Resource.h"
#include "Ant.h"


class Cell {

    public:

    Cell(CellType type, int xCoordinate, int yCoordinate, Resource resource);
    Cell(const Cell&);
    ~Cell() = default;
    int getX();
    int getY();
    CellType getType();
    Resource getResource();
    vector<const Ant*> getPresentAnts();
    void addAntToCell(Ant ant);


    private:

    CellType type_;
    int x_;
    int y_;
    Resource resource_;
    vector<const Ant*> present_ants_;
};


#endif //AIC21_CLIENT_CPP_CELL_H
