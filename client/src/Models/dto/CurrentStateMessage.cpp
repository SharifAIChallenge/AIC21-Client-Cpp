#include "CurrentStateMessage.h"

int CurrentStateMessage::getCurrentX() {
    return current_x;
}

int CurrentStateMessage::getCurrentY() {
    return current_y;
}

Resource CurrentStateMessage::getCurrentResource() {
    return (current_resource_type == 1)? Resource(GRASS, current_resource_value) : Resource(BREAD, current_resource_value);
}

int CurrentStateMessage::getHealth() {
    return health;
}

vector<Chat> CurrentStateMessage::getChats() {
    return chat_box;
}

vector<ClientCell> CurrentStateMessage::getAroundCells() {
    return around_cells;
}

vector<vector<Cell>> CurrentStateMessage::getVisibleCells(int height, int width) {
    vector<vector<Cell>> cells( height , vector<Cell> (width));
    for (ClientCell clientCell : around_cells) {
        Cell cell(
            clientCell.getCellType(),
            clientCell.getYCoordinate(),
            clientCell.getYCoordinate(),
            clientCell.getResource()
        );
        for (ClientAnt clientAnt : clientCell.getPresentAnts()) {
            cell.addAntToCell(
                Ant(
                    clientAnt.getAntType(),
                    clientAnt.getAntTeam()
                )
            );
        }
        cells[cell.getY()][cell.getX()] = cell;
    }
    return cells;
}