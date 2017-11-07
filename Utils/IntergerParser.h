#ifndef _INTERGER_PARSER_
#define _INTERGER_PARSER_

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

class IntergerParser{
public:
    static bool TryParse(string str, int& outValue);
private:
    static int Parse(string str);
};

#endif