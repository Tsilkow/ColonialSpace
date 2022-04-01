#pragma once

#include "common.hpp"

struct Transit
{
    std::shared_ptr<System> from;
    std::shared_ptr<System> to;
    int duration;
    int progress;

    Transit(std::shared_ptr<Universe>& universe, std::shared_ptr<System>& _from, std::shared_ptr<System>& _to);

    bool Progress();
};
    

class Fleet
{
private:
    std::shared_ptr<Universe> m_universe;
    std::string m_name;
    std::shared_ptr<System> m_location; // if null, it's in transit
    std::shared_ptr<Transit> m_transit; // if null, it's stationary
    std::shared_ptr<Faction> m_faction;
    std::set<std::shared_ptr<Ship>> m_ships;
public:
    Fleet() {;}
    
    void info(Log& log, bool deep=false);

    bool loadFromJson(json jsonParse, std::set<std::shared_ptr<Ship>>& global_ships);
    
    const std::string& getName() {return m_name; }
    bool isAtSystem() {return m_location != NULL; }
    const std::shared_ptr<System>& getLocation() {return m_location; }
    const std::shared_ptr<Faction>& getFaction() {return m_faction; }
    const std::set<std::shared_ptr<Ship>>& getShips() {return m_ships; }
};
