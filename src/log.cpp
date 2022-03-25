#include "log.hpp"


Log::Log(int indent_size):
    m_indent_size(indent_size),
    m_curr_indent(0)
{;}

void Log::print(std::string to_print)
{
    std::string indentation(m_curr_indent * m_indent_size, ' ');
    std::cout << indentation << to_print << std::endl;
}
