#include "universe.hpp"


bool Parameters::loadFromJson(json jsonParse)
{
    try{
	name = jsonParse["name"].get<std::string>();

	flight_speed_inv = 1.f/jsonParse["flight speed"].get<float>();
    }
    catch (json::exception& e)
    {
	std::cout << "INIT FILE ERROR IN UNIVERSE PARAMATERS = " << e.what() << std::endl;
	return false;
    }
    return true;
}

Universe::Universe():
    m_log(Log())
{
    m_log.print("NEW UNIVERSE CREATED");
}

void Universe::info()
{
    m_log.print("{");
    m_log.indent();
    m_log.print("Name = " + getName());
    
    m_log.print("Factions = {");
    m_log.indent();
    for(auto it = m_factions.begin(); it != m_factions.end(); ++it)
    {
	m_log.print((*it)->getName());
    }
    m_log.deindent();
    m_log.print("}");
    
    m_log.print("Systems = {");
    m_log.indent();
    for(auto it = m_systems.begin(); it != m_systems.end(); ++it)
    {
	m_log.print((*it)->getName());
    }
    m_log.deindent();
    m_log.print("}");
    
    m_log.print("Planets = {");
    m_log.indent();
    for(auto it = m_planets.begin(); it != m_planets.end(); ++it)
    {
	m_log.print((*it)->getName());
    }
    m_log.deindent();
    m_log.print("}");
    
    m_log.print("Colonies = {");
    m_log.indent();
    for(auto it = m_colonies.begin(); it != m_colonies.end(); ++it)
    {
	m_log.print((*it)->getName());
    }
    m_log.deindent();
    m_log.print("}");
    
    m_log.print("Fleets = {");
    m_log.indent();
    for(auto it = m_fleets.begin(); it != m_fleets.end(); ++it)
    {
	m_log.print((*it)->getName());
    }
    m_log.deindent();
    m_log.print("}");
    
    m_log.print("Ships = {");
    m_log.indent();
    for(auto it = m_ships.begin(); it != m_ships.end(); ++it)
    {
	m_log.print((*it)->getName());
    }
    m_log.deindent();
    m_log.print("}");
    
    m_log.deindent();
    m_log.print("}");
}
/*
void Universe::deep_info()
{
    ;
}*/


int Universe::calcFlight(const coords& a, const coords& b)
{
    return std::max(1, (int)std::round((b-a).length() * m_parameters.flight_speed_inv));
}


bool Universe::loadFromJson(json jsonParse)
{
    try{
	m_name = jsonParse["name"].get<std::string>();

	std::string template_file = jsonParse["template"].get<std::string>();
	m_parameters.loadFromJson(readUniverseTemplate(template_file)["universe template"].get<json>());
	
	json factions = jsonParse["factions"].get<json>();
	for(auto it = factions.begin(); it != factions.end(); ++it)
	{
	    auto jt = m_factions.insert(std::make_shared<Faction>()).first;
	    (*jt)->loadFromJson(*it, m_fleets, m_ships);
	}
	
	json systems = jsonParse["systems"].get<json>();
	for(auto it = systems.begin(); it != systems.end(); ++it)
	{
	    auto jt = m_systems.insert(std::make_shared<System>()).first;
	    (*jt)->loadFromJson(*it, m_planets, m_colonies);
	}
    }
    catch (json::exception& e)
    {
	std::cout << "INIT FILE ERROR IN UNIVERSE = " << e.what() << std::endl;
	return false;
    }
    return true;
}
