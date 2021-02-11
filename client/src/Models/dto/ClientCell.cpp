#include "ClientCell.h"

int ClientCell::getXCoordinate() {
    return cell_x;
}

int ClientCell::getYCoordinate() {
    return cell_y;
}

CellType ClientCell::getCellType() {
    if(cell_type == 0)
        return BASE;
    if(cell_type == 1)
        return EMPTY;
    return WALL;
}

Resource ClientCell::getResource() {
    return (resource_type == 1) ? Resource(GRASS, resource_value) : Resource(BREAD, resource_value);
}

vector<ClientAnt> ClientCell::getPresentAnts() {
    return ants;
}