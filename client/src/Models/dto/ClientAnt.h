#ifndef AIC21_CLIENT_CPP_CLIENTANT_H
#define AIC21_CLIENT_CPP_CLIENTANT_H

#include "enums.h"

class ClientAnt {

    public:

    AntTeam getAntTeam();
    AntType getAntType();


    private:

    int ant_team;
    int ant_type;

};


#endif // AIC21_CLIENT_CPP_CLIENTANT_H