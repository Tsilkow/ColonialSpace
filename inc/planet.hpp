#pragma once

#include "common.hpp"

class Planet
{
private:
    std::shared_ptr<Universe> m_universe;
    std::string m_name;
    std::shared_ptr<System> m_system;
    std::shared_ptr<Colony> m_colony;
public:
    Planet() {;}
    
    void info(Log& log, bool deep=false);

    bool loadFromJson(json jsonParse, std::set<std::shared_ptr<Colony>>& global_colonies);
    
    const std::string& getName() {return m_name; }
    const std::shared_ptr<System>& getSystem() {return m_system; }
    bool hasColony() {return (m_colony != NULL); }
    const std::shared_ptr<Colony>& getColony() {return m_colony; }
};
