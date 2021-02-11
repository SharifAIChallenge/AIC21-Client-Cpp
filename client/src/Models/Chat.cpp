#include "Chat.h"

Chat::Chat(string message, int turn) {
    message_ = message;
    turn_ = turn;
}

string Chat::getMessage() {
    return message_;
}

int Chat::getTurn() {
    return turn_;
}
