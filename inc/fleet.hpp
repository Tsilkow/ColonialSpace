#pragma once

#include "common.hpp"

class Fleet
{
private:
    std::string m_name;
    System* m_location;
    Faction* m_faction;
    std::set<std::shared_ptr<Ship>> m_ships;
public:
    Fleet() {;}
    
    void info(Log& log);

    bool loadFromJson(json jsonParse, std::set<std::shared_ptr<Ship>>& global_ships);
    
    const std::string& getName() {return m_name; }
    bool isAtSystem() {return (m_location != NULL); }
    const System* getLocation() {return m_location; }
    const Faction* getFaction() {return m_faction; }
    const std::set<std::shared_ptr<Ship>>& getShips() {return m_ships; }
};
