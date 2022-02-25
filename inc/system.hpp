#pragma once

#include "common.hpp"

class System
{
private:
    std::string m_name;
    coords m_position;
    std::set<std::shared_ptr<Planet>> m_planets;
public:
    const std::string& getName() {return m_name; }
    const coords& getPosition() {return m_position; }
    const std::set<std::shared_ptr<Planet>>& getPlanets() {return m_planets; }
};
