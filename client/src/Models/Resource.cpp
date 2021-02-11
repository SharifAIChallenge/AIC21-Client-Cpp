#include "Resource.h"

Resource::Resource(ResourceType type, int amount) {
    type_ = type;
    amount_ = amount;
}

ResourceType Resource::getType() {
    return type_;
}

int Resource::getAmount() {
    return amount_;
}