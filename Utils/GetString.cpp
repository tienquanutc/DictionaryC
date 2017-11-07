#include "GetString.h"

void GetLine(istream& is, string& str, int color){

    Console::setTextColor(color);
    do {
        getline(cin, str);
        if(str.size() == 0){
            Console::setTextColor(Constants::FAILED_COLOR);
            cout << Language::INVALID_INPUT_EMPTY << endl;
        }
        Console::setTextColor(color);
    }while(str.size() == 0);
}
