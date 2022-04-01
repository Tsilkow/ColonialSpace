#pragma once

#include "common.hpp"

class Ship
{
private:
    std::shared_ptr<Universe> m_universe;
    std::string m_name;
    std::shared_ptr<Fleet> m_fleet;
public:
    Ship() {;}
    
    void info(Log& log);

    bool loadFromJson(json jsonParse);
    
    const std::string& getName() {return m_name; }
    const std::shared_ptr<Fleet>& getFleet() {return m_fleet; }
};
