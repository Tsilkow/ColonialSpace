#include "planet.hpp"


void Planet::info(Log& log, bool deep)
{
    log.print("{");
    log.indent();
    log.print("Name = " + getName());
    

    if(hasColony())
    {
	log.print("Colony = {");
	log.indent();
	
	if(deep) m_colony->info(log);
	else log.print(m_colony->getName());
    
	log.deindent();
	log.print("}");
    }
    else log.print("Colony = No");
    
    log.deindent();
    log.print("}");
}

bool Planet::loadFromJson(json jsonParse, std::set<std::shared_ptr<Colony>>& global_colonies)
{
    try{
	m_name = jsonParse["name"].get<std::string>();

	if(!jsonParse["colony"].is_null())
	{
	    m_colony = std::make_shared<Colony>();
	    global_colonies.insert(m_colony);
	    
	    m_colony->loadFromJson(jsonParse["colony"].get<json>());
	}
    }
    catch (json::exception& e)
    {
	std::cout << "INIT FILE ERROR IN UNIVERSE = " << e.what() << std::endl;
	return false;
    }
    return true;
}
