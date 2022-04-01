#include "faction.hpp"


void Faction::info(Log& log, bool deep)
{
    log.print("{");
    log.indent();
    log.print("Name = " + getName());
    
    log.print("Colonies = {");
    log.indent();
    for(auto it = m_colonies.begin(); it != m_colonies.end(); ++it)
    {
	if(deep) (*it)->info(log);
	else log.print((*it)->getName());
    }
    log.deindent();
    log.print("}");
    
    log.print("Fleets = {");
    log.indent();
    for(auto it = m_fleets.begin(); it != m_fleets.end(); ++it)
    {
	if(deep) (*it)->info(log, true);
	else log.print((*it)->getName());
    }
    log.deindent();
    log.print("}");
    
    log.deindent();
    log.print("}");
}

bool Faction::loadFromJson(json jsonParse, std::set<std::shared_ptr<Fleet>>& global_fleets,
		      std::set<std::shared_ptr<Ship>>& global_ships)
{
    try{
	m_name = jsonParse["name"].get<std::string>();

	json fleets = jsonParse["fleets"].get<json>();
	for(auto it = fleets.begin(); it != fleets.end(); ++it)
	{
	    auto jt = m_fleets.insert(std::make_shared<Fleet>()).first;
	    global_fleets.insert(*jt);
	    
	    (*jt)->loadFromJson(*it, global_ships);
	}
    }
    catch (json::exception& e)
    {
	std::cout << "INIT FILE ERROR = " << e.what() << std::endl;
	return false;
    }
    return true;
}
