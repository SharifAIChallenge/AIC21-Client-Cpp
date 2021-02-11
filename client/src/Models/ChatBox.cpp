#include "ChatBox.h"

ChatBox::ChatBox(vector<Chat> allChats) {
    for(Chat chat : allChats)
        all_chats_.push_back(&chat);
}

vector<Chat*> ChatBox::getAllChatsOfTurn(int turnNumber) {
    vector<Chat*> output;
    for(Chat* chat : all_chats_)
        if(chat->getTurn() == turnNumber)
            output.push_back(chat);
    return output;
}

vector<Chat*> ChatBox::getAllChats() {
    return all_chats_;
}
