#include "planet.hpp"


void Planet::info(Log& log)
{
    std::string result = "{\n";
    result += "    Name = " + m_name + "\n";
    if(this->hasColony()) result += "    Colony = Yes\n";
    else result += "    Colony = No\n";
    result += "}\n";
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
