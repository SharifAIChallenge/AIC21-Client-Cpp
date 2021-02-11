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



// class Cell {
// public:
//     Cell(int row, int col);

//     Cell(const Cell&);


//     ~Cell() = default;

//     bool operator==(const Cell &rhs) const;

//     bool operator!=(const Cell &rhs) const;

//     int getRow() const;

//     int getCol() const;

//     std::vector<const Unit *> getUnits() const;

// private:
//     int row_;
//     int col_;
//     std::vector<const Unit *> units_;

//     friend class TurnMessage;
//     friend class ShutdownMessage;
//     friend class Map;
// };


#endif //AIC21_CLIENT_CPP_CELL_H
