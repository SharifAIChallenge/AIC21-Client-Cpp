#ifndef AIC21_CLIENT_CPP_RESOURCE_H
#define AIC21_CLIENT_CPP_RESOURCE_H

#include "Models/enums.h"

class Resource {

    public:

    Resource(ResourceType type, int amount);
    ResourceType getType();
    int getAmount();


    private:

    ResourceType type_;
    int amount_;

};

#endif //AIC21_CLIENT_CPP_RESOURCE_H