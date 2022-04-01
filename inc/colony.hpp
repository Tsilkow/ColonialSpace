#pragma once

#include "common.hpp"

class Colony
{
private:
    std::shared_ptr<Universe> m_universe;
    std::string m_name;
    std::shared_ptr<Planet> m_planet;
    std::shared_ptr<Faction> m_faction;
public:
    Colony() {;}
    
    void info(Log& log);

    bool loadFromJson(json jsonParse);
    
    const std::string& getName() {return m_name; }
    const std::shared_ptr<Planet>& getPlanet() {return m_planet; }
    const std::shared_ptr<Faction>& getFaction() {return m_faction; }
};
