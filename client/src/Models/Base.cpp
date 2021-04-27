#include "Base.h"

Base::Base(int x, int y) {
    x_ = x;
    y_ = y;
}

int Base::getX() const {
    return x_;
}

int Base::getY() const {
    return y_;
}
