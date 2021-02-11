#include "Map.h"

Map::Map(vector<vector<Cell>> cells, int width, int height, int manhattanDistance, int currentX, int currentY) {
    for(vector<Cell> row : cells) {
        vector<Cell*> thisRow; 
        for(Cell cell : row)
            thisRow.push_back(&cell);
        cells_.push_back(thisRow);
    }
    width_ = width;
    height = height_;
    manhattan_distance_ = manhattanDistance;
    cells_ = createCompressedCells(currentX, currentY);
}

Cell* Map::getCell(int dx, int dy, int distance) {
    if (abs(dx) + abs(dy) > distance)
        return NULL;
    if (distance + dx >= width_ | distance + dx < 0)
        return NULL;
    if (distance + dy < 0 | distance + dy >= height_)
        return NULL;
    return cells_[distance + dy][distance + dx];
}

vector<vector<Cell*>> Map::createCompressedCells(int midX, int midY) {
    vector<vector<Cell*>> compressedCells( 2 * manhattan_distance_ , vector<Cell*> (2 * manhattan_distance_));
    int starti = max(midY - manhattan_distance_, 0), endi = min(midY + manhattan_distance_, height_);
    int startj = max(midX - manhattan_distance_, 0), endj = min(midX + manhattan_distance_, width_);
    int xTransform = manhattan_distance_ - midX;
    int yTransform = manhattan_distance_ - midY;

    for (int i = starti; i < endi; i++) {
        vector<Cell*> row;
        for (int j = startj; j < endj; j++) {
            row.push_back(cells_[j][i]);
            compressedCells[j + yTransform][i + xTransform] = cells_[j][i];
        }
    }

    return compressedCells;
}