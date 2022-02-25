#pragma once

#include "common.hpp"

class Planet
{
private:
    std::string m_name;
    System* m_system;
    Colony* m_colony;
public:
    const std::string& getName() {return m_name; }
    const System* getSystem() {return m_system; }
    bool hasColony() {return (m_colony != NULL); }
    const Colony* getColony() {return m_colony; }
};
