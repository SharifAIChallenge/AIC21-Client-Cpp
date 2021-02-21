#ifndef AIC21_CLIENT_CPP_CELL_H
#define AIC21_CLIENT_CPP_CELL_H

#include <vector>
#include "Models/enums.h"
#include "Models/Resource.h"
#include "Models/Ant.h"


class Cell {

    public:

    Cell() = default;
    ~Cell() = default;
    Cell(CellType type, int xCoordinate, int yCoordinate, Resource resource);
    Cell(const Cell&);
    int getX();
    int getY();
    CellType getType();
    Resource* getResource();
    vector<const Ant*> getPresentAnts();
    void addAntToCell(Ant ant);


    private:

    int x_;
    int y_;
    CellType type_;
    Resource* resource_ = nullptr;
    vector<const Ant*> present_ants_;
};


#endif //AIC21_CLIENT_CPP_CELL_H
