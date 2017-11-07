#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include <limits>
#include <vector>
#include "MenuItem.h"
#include "../Resources/Constants.h"
#include "../Resources/Language.h"
#include "../Utils/IntergerParser.h"
#include "../Utils/Console.h"
#include "../Utils/GetString.h"

using namespace std;


template <class T>
class Menu {
private:
    vector<MenuItem<T>> _items;
    int choiceToExit;
public:
    Menu();
    void addItem(const MenuItem<T>& item);
    // Should implement Remove??
    void excute();

    static const int DEFAULT_EXIT_CHOICE = 0;
};

template <class T>
Menu<T>::Menu() {
    choiceToExit = DEFAULT_EXIT_CHOICE;
}

template <class T>
void Menu<T>::addItem(const MenuItem<T>& item) {
    _items.push_back(item);
}

template <class T>
void Menu<T>::excute() {
    Console::clear();
    const int max = _items.size();
    string choiceStr;
    int choice = -1;

    do {
        Console::setTextColor(Constants::HEADER_MENU);
        cout << Language::TITTLE << endl;
        Console::setTextColor(Constants::DEFAULT_COLOR);
        for (int i = 1; i < max; ++i) {
            cout << i << " " << _items.at(i) << endl;
        }
        cout << "0 " << _items.at(0) << endl;
        while (true) {
            choice = -1;
            Console::setTextColor(Constants::HEADER_MENU);
            cout << Language::CHOICE;
            GetLine(cin, choiceStr, Constants::CHOICE);
            if (!IntergerParser::TryParse(choiceStr, choice)) {
                Console::setTextColor(Constants::FAILED_COLOR);
                cout << Language::INVALID_INPUT_NUMBER << _items.size() - 1
                     << endl;
            } else {
                if (choice < 0 || choice >= max) {
                    Console::setTextColor(Constants::FAILED_COLOR);
                    cout << Language::INVALID_INPUT_RANGE << _items.size() - 1
                         << endl;
                } else {
                    break;
                }
            }
        }
        _items.at(choice).excute();
    } while (true);
}

#endif
