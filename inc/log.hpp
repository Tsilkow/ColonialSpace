#pragma once

#include <iostream>
#include <string>


class Log
{
private:
    int m_curr_indent;
    int m_indent_size;
public:
    Log(int indent_size=4);

    void print(std::string to_print);

    void indent() {++m_curr_indent; }
    
    void deindent() {--m_curr_indent; }
};
