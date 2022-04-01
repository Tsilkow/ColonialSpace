#include "fleet.hpp"


Transit::Transit(std::shared_ptr<Universe>& universe, std::shared_ptr<System>& _from,
		 std::shared_ptr<System>& _to):
    from(_from),
    to(_to),
    progress(0)
{
    duration = universe->calcFlight(from->getPosition(), to->getPosition());
}

bool Transit::Progress()
{
    ++progress;
    if(progress == duration) return true;
    return false;
}


void Fleet::info(Log& log)
{
    log.print("{");
    log.indent();
    log.print("Name = " + getName());
    
    log.print("Ships = {");
    log.indent();
    for(auto it = m_ships.begin(); it != m_ships.end(); ++it)
    {
	log.print((*it)->getName());
    }
    log.deindent();
    log.print("}");
    
    log.deindent();
    log.print("}");
}

bool Fleet::loadFromJson(json jsonParse, std::set<std::shared_ptr<Ship>>& global_ships)
{
    try{
	m_name = jsonParse["name"].get<std::string>();

	json ships = jsonParse["ships"].get<json>();
	for(auto it = ships.begin(); it != ships.end(); ++it)
	{
	    auto jt = m_ships.insert(std::make_shared<Ship>()).first;
	    global_ships.insert(*jt);
	    
	    (*jt)->loadFromJson(*it);
	}
    }
    catch (json::exception& e)
    {
	std::cout << "INIT FILE ERROR = " << e.what() << std::endl;
	return false;
    }
    return true;
}
