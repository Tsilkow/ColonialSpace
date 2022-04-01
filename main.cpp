#include "common.hpp"


using namespace std;


int main(void)
{
    Universe universe;

    universe.loadFromJson(readGameState("nominal.json"));
    universe.info(true);

    cout << "What sound do you make, when you scream?" << endl;
    
    return 0;
}
