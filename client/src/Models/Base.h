#ifndef AIC21_CLIENT_CPP_BASE_H
#define AIC21_CLIENT_CPP_BASE_H


class Base {
private:
    int x_;
    int y_;

public:
    Base(int x, int y);
    int getX() const;
    int getY() const;
};


#endif //AIC21_CLIENT_CPP_BASE_H
