#include "Cell.h"


Cell::Cell(CellType type, int xCoordinate, int yCoordinate, Resource resource) {
    Cell();
    x_ = xCoordinate;
    y_ = yCoordinate;
    type_ = type;
    resource_ = &resource;
    present_ants_;
}

Cell::Cell(const Cell& obj) {
    Cell();
    x_ = obj.x_;
    y_ = obj.y_;
    type_ == obj.type_;
    resource_ = obj.resource_;
    present_ants_ = obj.present_ants_;
}

int Cell::getX() {
    return x_;
}

int Cell::getY() {
    return y_;
}

CellType Cell::getType() {
    return type_;
}

Resource* Cell::getResource() {
    return resource_;
}

vector<const Ant*> Cell::getPresentAnts() {
    return present_ants_;
}

void Cell::addAntToCell(Ant ant) {
    present_ants_.push_back(&ant);
}
