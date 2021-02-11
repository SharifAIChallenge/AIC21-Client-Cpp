#include "ClientAnt.h"

AntTeam ClientAnt::getAntTeam() {
    return (ant_team == 1) ? ENEMY : ALLY;
}

AntType ClientAnt::getAntType() {
    return (ant_team == 1) ? SARBAZ : KARGAR;
}
