#ifndef AIC21_CLIENT_CPP_CURRENT_STATE_MESSAGE_H
#define AIC21_CLIENT_CPP_CURRENT_STATE_MESSAGE_H

#include "Core/Message/Message.h"
#include "Core/Message/Parse/ParseError.h"
#include "Core/Message/Parse/AntDTO.h"
#include "Core/Message/Parse/CellDTO.h"
#include "Models/Game.h"
#include "Models/enums.h"
#include <vector>
using namespace std;


class CurrentStateMessage final : public Message {

public:

    explicit CurrentStateMessage(const json &root);
    explicit CurrentStateMessage(const string &json_form);
    void updateGame(Game* game);


private:

    int getCurrentX();
    int getCurrentY();
    int getHealth();
    Resource getCurrentResource();

    vector<Chat> parseChats();
    vector<CellDTO> parseAroundCellsDTO();
    static CellDTO parseCellDTO(json cellJsonForm);
};

#endif // AIC21_CLIENT_CPP_CURRENT_STATE_MESSAGE_H
