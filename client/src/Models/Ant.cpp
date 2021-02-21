#include "Ant.h"
#include "enums.h"

Ant::Ant(AntType type, AntTeam team)
{
    type_ = type;
    team_ = team;
    carrying_resource_ = NULL;
    x_ = -1;
    y_ = -1;
    health_ = -1;
    view_distance_ = -1;
}

Ant::Ant(AntType type, AntTeam team, int viewDistance, Map map, CurrentStateMessage state)
{
    type_ = type;
    team_ = team;
    carrying_resource_ = &state.getCurrentResource();
    x_ = state.getCurrentX();
    y_ = state.getCurrentY();
    health_ = state.getHealth();
    visible_map_ = &map;
    view_distance_ = viewDistance;
}

int Ant::getX()
{
    return x_;
}

int Ant::getY()
{
    return y_;
}

int Ant::getHealth()
{
    return health_;
}

int Ant::getViewDistance()
{
    return view_distance_;
}

Cell *Ant::getNeighborCell(int xStep, int yStep)
{
    return getMapCell(xStep, yStep);
}

Cell *Ant::getCurrentCell()
{
    return getNeighborCell(0, 0);
}

AntType Ant::getType()
{
    return type_;
}

AntTeam Ant::getTeam()
{
    return team_;
}

Resource *Ant::getCarryingResource()
{
    return carrying_resource_;
}

Cell *Ant::getMapCell(int dx, int dy)
{
    return visible_map_->getCell(dx, dy, view_distance_);
}