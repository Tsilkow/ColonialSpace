#include "system.hpp"


void System::info(Log& log)
{
    log.print("{");
    log.indent();
    log.print("Name = " + getName());
    
    log.print("Planets = {");
    log.indent();
    for(auto it = m_planets.begin(); it != m_planets.end(); ++it)
    {
	log.print((*it)->getName());
    }
    log.deindent();
    log.print("}");
    
    log.deindent();
    log.print("}");
}

bool System::loadFromJson(json jsonParse, std::set<std::shared_ptr<Planet>>& global_planets,
			  std::set<std::shared_ptr<Colony>>& global_colonies)
{
    try{
	m_name = jsonParse["name"].get<std::string>();
	
	json planets = jsonParse["planets"].get<json>();
	for(auto it = planets.begin(); it != planets.end(); ++it)
	{
	    auto jt = m_planets.insert(std::make_shared<Planet>()).first;
	    global_planets.insert(*jt);
	    
	    (*jt)->loadFromJson(*it, global_colonies);
	}
    }
    catch (json::exception& e)
    {
	std::cout << "INIT FILE ERROR IN UNIVERSE = " << e.what() << std::endl;
	return false;
    }
    return true;
}
