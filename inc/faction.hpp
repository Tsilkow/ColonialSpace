#pragma once

#include "common.hpp"

class Faction
{
private:
    std::string m_name;
    std::set<std::shared_ptr<Colony>> m_colonies;
    std::set<std::shared_ptr<Fleet>> m_fleets;
public:
    const std::string& getName() {return m_name; }
    const std::set<std::shared_ptr<Colony>>& getColonies() {return m_colonies; }
    const std::set<std::shared_ptr<Fleet>>& getFleets() {return m_fleets; }
};
