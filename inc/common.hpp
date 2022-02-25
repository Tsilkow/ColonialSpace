#pragma once

#include <iostream>
#include <string>
#include <set>
#include <memory>


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

    coords(int temp_x, int temp_y):
	x(temp_x), y(temp_y)
	{;}
};

coords operator- (const coords& a, const coords& b);


#include "universe.hpp"
#include "faction.hpp"
#include "system.hpp"
#include "planet.hpp"
#include "colony.hpp"
#include "fleet.hpp"
#include "ship.hpp"
