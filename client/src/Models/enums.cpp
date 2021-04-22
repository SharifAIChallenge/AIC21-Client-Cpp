#include "enums.h"


CellType EnumUtils::getCellTypeByInt(int cellType) {
    switch (cellType)
    {
        case 0:
            return BASE;
        case 1:
            return EMPTY;
        case 2:
            return WALL;
        default:
            throw ParseError("Unsupported cell_type : "+ to_string(cellType));
    }
}

ResourceType EnumUtils::getResourceTypeByInt(int resourceType) {
    switch (resourceType)
    {
        case 0:
            return GRASS;
        case 1:
            return BREAD;
        case 2:
            return NONE;
        default:
            throw ParseError("Unsupported resource_type : "+ std::to_string(resourceType));
    }
}

AntType EnumUtils::getAntTypeByInt(int antType) {
    switch (antType)
    {
        case 0:
            return SARBAZ;
        case 1:
            return KARGAR;
        default:
            throw ParseError("Unsupported ant_type : "+ std::to_string(antType));
    }
}

AntTeam EnumUtils::getAntTeamByInt(int antTeam) {
    switch (antTeam)
    {
        case 0:
            return ALLY;
        case 1:
            return ENEMY;
        default:
            throw ParseError("Unsupported ant_team : "+ std::to_string(antTeam));
    }
}
