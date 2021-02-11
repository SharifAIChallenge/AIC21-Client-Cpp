#ifndef AIC21_CLIENT_CPP_CLIENTCELL_H
#define AIC21_CLIENT_CPP_CLIENTCELL_H

using namespace std;
#include <vector>
#include "Models/dto/ClientAnt.h"
#include "Models/Resource.h"

class ClientCell {

    private:

    int cell_x;
    int cell_y;
    int cell_type;
    int resource_value;
    int resource_type;
    vector<ClientAnt> ants;


    public:

    ClientCell() = default;
    ~ClientCell() = default;
    int getXCoordinate();
    int getYCoordinate();
    CellType getCellType();
    Resource getResource();
    vector<ClientAnt> getPresentAnts();

};


#endif // AIC21_CLIENT_CPP_CLIENTCELL_H