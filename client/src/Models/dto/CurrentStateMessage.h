#ifndef AIC21_CLIENT_CPP_CURRENTSTATEMESSAGE_H
#define AIC21_CLIENT_CPP_CURRENTSTATEMESSAGE_H

using namespace std;
#include <vector>
#include "Chat.h"
#include "Cell.h"
#include "ClientCell.h"

class CurrentStateMessage {

    private:

    int current_x;
    int current_y;
    int current_resource_value;
    int current_resource_type;
    int health;
    vector<Chat> chat_box;
    vector<ClientCell> around_cells;


    public:

    int getCurrentX();
    int getCurrentY();
    Resource getCurrentResource();
    int getHealth();
    vector<Chat> getChats();
    vector<ClientCell> getAroundCells();
    vector<vector<Cell>> getVisibleCells(int height, int width);
};

#endif // AIC21_CLIENT_CPP_CURRENTSTATEMESSAGE_H