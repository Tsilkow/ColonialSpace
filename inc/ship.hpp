#pragma once

#include "common.hpp"

class Ship
{
private:
    std::string m_name;
    Fleet* m_fleet;
public:
    const std::string& getName() {return m_name; }
    const Fleet* getFleet() {return m_fleet; }
};