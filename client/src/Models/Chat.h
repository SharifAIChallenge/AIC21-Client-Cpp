#ifndef AIC21_CLIENT_CPP_CHAT_H
#define AIC21_CLIENT_CPP_CHAT_H

using namespace std;
#include <string>

class Chat {

    public:

    Chat(string message, int turn);
    string getMessage();
    int getTurn();


    private:

    string message_;
    int turn_;

};

#endif //AIC21_CLIENT_CPP_CHAT_H