#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <memory>
#include "json.hpp"

using namespace nlohmann;

class Universe;
class Faction;
class System;
class Planet;
class Colony;
class Fleet;
class Ship;


struct coords
{
    int x;
    int y;

    coords(int temp_x=-2137, int temp_y=-2137):
	x(temp_x), y(temp_y)
	{;}
};

coords operator- (const coords& a, const coords& b);


#include "log.hpp"
#include "universe.hpp"
#include "faction.hpp"
#include "system.hpp"
#include "planet.hpp"
#include "colony.hpp"
#include "fleet.hpp"
#include "ship.hpp"
