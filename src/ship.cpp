#include "ship.hpp"


void Ship::info(Log& log)
{
    log.print("{");
    log.indent();
    log.print("Name = " + getName());
    
    log.deindent();
    log.print("}");
}

bool Ship::loadFromJson(json jsonParse)
{
    try{
	m_name = jsonParse["name"].get<std::string>();
    }
    catch (json::exception& e)
    {
	std::cout << "INIT FILE ERROR = " << e.what() << std::endl;
	return false;
    }
    return true;
}
