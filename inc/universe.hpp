#pragma once

#include "common.hpp"

class Universe
{
private:
    std::string m_name;
    Log m_log;
    std::set<std::shared_ptr<Faction>> m_factions;
    std::set<std::shared_ptr<System>> m_systems;
    std::set<std::shared_ptr<Planet>> m_planets;
    std::set<std::shared_ptr<Colony>> m_colonies;
    std::set<std::shared_ptr<Fleet>> m_fleets;
    std::set<std::shared_ptr<Ship>> m_ships;
public:
    Universe();
    
    void info();

    bool loadFromJson(json jsonParse);
    
    const std::string& getName() {return m_name; }
};
