#include "IntergerParser.h"

bool IntergerParser::TryParse(string str, int& outValue) {
    for(char c : str)
    {
        if(!isdigit(c))
            return false;
    }
    outValue = IntergerParser::Parse(str);
    return true;
}

int IntergerParser::Parse(string str){
    stringstream sstream;
    int value;
    sstream << str;
    sstream >> value;
    return value;
}
