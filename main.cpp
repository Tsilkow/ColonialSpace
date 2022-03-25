#include "common.hpp"


using namespace std;


json readGameState(std::string filename)
{
    std::fstream file("data/game-states/" + filename);
    json result;
    file >> result;

    return result;
}

int main(void)
{
    Universe universe;

    universe.loadFromJson(readGameState("nominal.json")["universe"].get<json>());
    universe.info();

    cout << "What sound do you make, when you scream?" << endl;
    
    return 0;
}
