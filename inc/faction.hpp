#pragma once

#include "common.hpp"

class Faction
{
private:
    std::shared_ptr<Universe> m_universe;
    std::string m_name;
    std::set<std::shared_ptr<Colony>> m_colonies;
    std::set<std::shared_ptr<Fleet>> m_fleets;
public:
    Faction() {;}
    
    void info(Log& log);

    bool loadFromJson(json jsonParse, std::set<std::shared_ptr<Fleet>>& global_fleets,
		      std::set<std::shared_ptr<Ship>>& global_ships);
    
    const std::string& getName() {return m_name; }
    const std::set<std::shared_ptr<Colony>>& getColonies() {return m_colonies; }
    const std::set<std::shared_ptr<Fleet>>& getFleets() {return m_fleets; }
};
