#include "common.hpp"

coords operator- (const coords& a, const coords& b)
{
    return coords(a.x-b.x, a.y-b.y);
}

json readGameState(std::string filename)
{
    std::fstream file("data/game-states/" + filename);
    json result;
    file >> result;

    return result["universe"].get<json>();
}

json readUniverseTemplate(std::string filename)
{
    std::fstream file("data/universe-templates/" + filename);
    json result;
    file >> result;

    return result["universe template"].get<json>();;
}
