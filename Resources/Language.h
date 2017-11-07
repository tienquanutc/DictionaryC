#ifndef _LANGUAGE_H_
#define _LANGUAGE_H_

#include <string>
using namespace std;

// TODO: Should divide more class
class Language {
public:
    static const string TITTLE;
    static const string CHOICE;
    static const string TYPE_ANY_CONTINUE;
    
    static const string INVALID_INPUT_EMPTY;
    static const string INVALID_INPUT_RANGE;
    static const string INVALID_INPUT_NUMBER;
    

    static const string DATABASE_PATH;
    static const string NOT_FOUND_DATA_BASE;
    static const string SAVE_DATA_BASE_FAILED;
    static const string SAVE_DATA_BASE_SUCCESS;

    static const string TYPE_ENGLISH_WORD;
    static const string TYPE_ENGLISH_WORD_OR_INDEX_UPDATE;
    static const string TYPE_VIETNAMESE_WORD;

    static const string NOT_FOUND_ANY_WORD;
    static const string NOT_FOUND_WORD;

    static const string ADD_WORD_SUCCESS;
    static const string ADD_WORD_FAILED;

    static const string TYPE_ENGLISH_UPDATE;
    static const string UPDATE_WORD;
    static const string UPDATE_WORD_SUCCESS;
    static const string UPDATE_WORD_FAILED;
    static const string NOT_FOUND_WORD_TO_UPDATE;

    static const string TYPE_ENGLISH_REMOVE;
     static const string TYPE_ENGLISH_WORD_OR_INDEX_REMOVE;
    static const string REMOVE_WORD_SUCCESS;
    static const string REMOVE_WORD_FAILED;
    static const string NOT_FOUND_WORD_TO_REMOVE;

    static const string MENU_EXIT;
    static const string MENU_ALL_WORD;
    static const string MENU_ADD_WORD;
    static const string MENU_UPDATE_WORD;
    static const string MENU_FIND_WORD;
    static const string MENU_REMOVE_WORD;
    static const string MENU_FIND_APPROXIMATELY;

    static const string ADD_DUPLICATE_WORD;
};


#endif
