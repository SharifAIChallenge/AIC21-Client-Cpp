#include "Utility/Logger.h"
#include "Utility/Utility.h"
#include "CurrentStateMessage.h"

using namespace std;


CurrentStateMessage::CurrentStateMessage(const json &root) : Message(root) {
    if (getType() != "4")
        throw ParseError("Invalid game state message");
}

CurrentStateMessage::CurrentStateMessage(const string &json_form) : Message(json_form) {
    if (getType() != "4")
        throw ParseError("Invalid game state message");
}

int CurrentStateMessage::getCurrentX() const {
    return m_root_["current_x"];
}

int CurrentStateMessage::getCurrentY() const {
    return m_root_["current_y"];
}

int CurrentStateMessage::getHealth() const {
    return m_root_["health"];
}

Resource CurrentStateMessage::getCurrentResource() {
    int currentResourceType = m_root_["current_resource_type"];
    int currentResourceValue = m_root_["current_resource_value"];

    if(currentResourceType == 0)
        return Resource(BREAD, currentResourceValue);
    if(currentResourceType == 1)
        return Resource(GRASS, currentResourceValue);
    if(currentResourceType == 2)
        return Resource(NONE, currentResourceValue);

    throw ParseError("Unsupported resource_type : " + to_string(currentResourceType));
}

vector<Chat> CurrentStateMessage::parseChats() {
    vector<Chat> output;
    json chatBox = m_root_["chat_box"];
    string text;
    int turn;
    for(json chat : chatBox) {
        text = chat["text"];
        turn = chat["turn"];
        output.push_back(Chat(text, turn));
    }
    return output;
}

CellType getCellTypeByInt(int cellType) {
    switch (cellType)
    {
    case 0:
        return BASE;
    case 1:
        return EMPTY;
    case 2:
        return WALL;
    default:
        throw ParseError("Unsupported cell_type : "+ to_string(cellType));
    }
}

ResourceType getResourceTypeByInt(int resourceType) {
    switch (resourceType)
    {
    case 0:
        return BREAD;
    case 1:
        return GRASS;
    case 2:
        return NONE;
    default:
        throw ParseError("Unsupported resource_type : "+ to_string(resourceType));
    }
}

AntType getAntTypeByInt(int antType) {
    switch (antType)
    {
    case 0:
        return SARBAZ;
    case 1:
        return KARGAR;
    default:
        throw ParseError("Unsupported ant_type : "+ to_string(antType));
    }
}

AntTeam getAntTeamByInt(int antTeam) {
    switch (antTeam)
    {
    case 0:
        return ALLY;
    case 1:
        return ENEMY;
    default:
        throw ParseError("Unsupported ant_team : "+ to_string(antTeam));
    }
}

CellDTO CurrentStateMessage::parseCellDTO(const json &cellJsonForm) {
    int cellX = cellJsonForm["cell_x"];
    int cellY = cellJsonForm["cell_y"];
    int cellTypeInt = cellJsonForm["cell_type"];
    int resourceTypeInt = cellJsonForm["resource_type"];
    int resourceValue = cellJsonForm["resource_value"];
    int antTypeInt, antTeamInt;
    CellDTO out = CellDTO(cellX, cellY, getCellTypeByInt(cellTypeInt), resourceValue, getResourceTypeByInt(resourceTypeInt));
    json ants = cellJsonForm["ants"];
    for(json ant : ants) {
        antTypeInt = ant["ant_type"];
        antTeamInt = ant["ant_team"];
        out.addAnt(AntDTO(getAntTeamByInt(antTeamInt), getAntTypeByInt(antTypeInt)));
    }
    return out;
}

vector<CellDTO> CurrentStateMessage::parseAroundCellsDTO() {
    vector<CellDTO> output;
    json aroundCells = m_root_["around_cells"];
    for(const json& cell : aroundCells)
        output.push_back(parseCellDTO(cell));
    return output;
}

void CurrentStateMessage::updateGame(Game* game) {
    // TODO implement
}
