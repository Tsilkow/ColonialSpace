#pragma once

#include "common.hpp"

class Colony
{
private:
    std::string m_name;
    Planet* m_planet;
    Faction* m_faction;
public:
    const std::string& getName() {return m_name; }
    const Planet* getPlanet() {return m_planet; }
    const Faction* getFaction() {return m_faction; }
};
