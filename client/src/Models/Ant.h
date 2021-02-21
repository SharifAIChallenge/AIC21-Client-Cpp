#ifndef AIC21_CLIENT_CPP_ANT_H
#define AIC21_CLIENT_CPP_ANT_H

#include <vector>
#include "Models/enums.h"
#include "Models/Resource.h"
#include "Models/Cell.h"
#include "Models/Map.h"
#include "Models/dto/CurrentStateMessage.h"

class Ant {

    public:

    Ant() = default;
    Ant(AntType type, AntTeam team);
    Ant(AntType type, AntTeam team, int viewDistance, Map map, CurrentStateMessage state);
    int getX();
    int getY();
    int getHealth();
    int getViewDistance();
    Cell* getNeighborCell(int xStep, int yStep);
    Cell* getCurrentCell();
    AntType getType();
    AntTeam getTeam();
    Resource* getCarryingResource();


    private:

    int x_;
    int y_;
    int health_;
    int view_distance_;
    AntType type_;
    AntTeam team_;
    Resource* carrying_resource_;
    Map* visible_map_;
    Cell* getMapCell(int dx, int dy);
};

#endif //AIC21_CLIENT_CPP_ANT_H