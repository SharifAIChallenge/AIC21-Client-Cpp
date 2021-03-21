#include "ChatBox.h"

ChatBox::ChatBox(vector<Chat*> &allChats) {
    all_chats_ = allChats;
}

vector<Chat*> ChatBox::getAllChatsOfTurn(int turnNumber) {
    vector<Chat*> output;
    for(Chat* chat : all_chats_)
        if(chat->getTurn() == turnNumber)
            output.push_back(chat);
    return output;
}

vector<Chat*>* ChatBox::getAllChats() {
    return &all_chats_;
}
