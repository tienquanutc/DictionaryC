#include "Program.h"

void Program::initMenu() {
    _menu.addItem(MenuItem<Program>(this, &Program::exit, Language::MENU_EXIT));
    _menu.addItem(MenuItem<Program>(this, &Program::allWords, Language::MENU_ALL_WORD));
    _menu.addItem(MenuItem<Program>(this, &Program::addWords, Language::MENU_ADD_WORD));
    _menu.addItem(MenuItem<Program>(this, &Program::updateWords, Language::MENU_UPDATE_WORD));
    _menu.addItem(MenuItem<Program>(this, &Program::findWords, Language::MENU_FIND_WORD));
    _menu.addItem(MenuItem<Program>(this, &Program::removeWords, Language::MENU_REMOVE_WORD));
    _menu.addItem(MenuItem<Program>(this, &Program::findApproximately,Language::MENU_FIND_APPROXIMATELY));
}

void Program::Initialize() {
    LoadDataFromFile();
    initMenu();
}

void Program::LoadDataFromFile() {
    fstream fin;
    fin.open(Language::DATABASE_PATH, ios_base::in);
    if (fin.fail()) {
        Console::setTextColor(Constants::FAILED_COLOR);
        cout << Language::NOT_FOUND_DATA_BASE << endl;
        fin.close();
        return;
    }
    fin >> _dictionary;
    fin.close();
}

void Program::SaveDataToFile() {
    fstream fout;
    fout.open(Language::DATABASE_PATH, ios_base::out);
    if (fout.fail()) {
        Console::setTextColor(Constants::FAILED_COLOR);
        cout << Language::SAVE_DATA_BASE_FAILED << endl;
        fout.close();
        return;
    }
    fout << _dictionary;
	fout.close();
	Console::setTextColor(Constants::SUCCESS_COLOR);
	cout << Language::SAVE_DATA_BASE_SUCCESS << endl;
}

void Program::printWord(const int index, const Word& word) {
    Console::setTextColor(RED);
    cout << setw(3) << index << ". " << word;
}

Program::Program() {
    Initialize();
}

void Program::findApproximately() {
    Console::clear();
    Console::setTextColor(Constants::HEADER_MENU);
    cout << "***" <<Language::MENU_FIND_APPROXIMATELY << "***" << endl;

    string en;
    Console::setTextColor(Constants::DEFAULT_COLOR);
    cout << Language::TYPE_ENGLISH_WORD;
    Console::setTextColor(Constants::ENG_COLOR);
    GetLine(cin, en, Constants::ENG_COLOR);
    const vector<Word> vector = _dictionary.findApproximately(en);
    if (!vector.empty()) {
        for (auto& v : vector)
            cout << v << endl;
    } else{
        Console::setTextColor(Constants::FAILED_COLOR);
        cout << Language::NOT_FOUND_ANY_WORD;
    }
    pressAnyContinue();
}

void Program::addWords() {
    Console::clear();
    Console::setTextColor(Constants::HEADER_MENU);
    cout << "***" <<Language::MENU_ADD_WORD << "***" << endl;
    //	Console::gotoxy()
    string en, vi;
    Console::setTextColor(Constants::DEFAULT_COLOR);
    cout << Language::TYPE_ENGLISH_WORD;
    GetLine(cin, en, Constants::ENG_COLOR);
    if(_dictionary.find(en) == Word::NOT_FOUND){
        Console::setTextColor(Constants::DEFAULT_COLOR);
        cout << Language::TYPE_VIETNAMESE_WORD;
        GetLine(cin, vi, Constants::VIET_COLOR);
        _dictionary.addOrUpdate(en, vi);
        Console::setTextColor(Constants::SUCCESS_COLOR);
        cout << Language::ADD_WORD_SUCCESS << endl;
    }else{
        Console::setTextColor(Constants::FAILED_COLOR);
        cout << Language::ADD_DUPLICATE_WORD << endl;
    }
    pressAnyContinue();
}

void Program::updateWords() {
    Console::clear();
    Console::setTextColor(Constants::HEADER_MENU);
    cout << "***" <<Language::MENU_UPDATE_WORD << "***" << endl;
    //	Console::gotoxy()
    string en, vi;
    Console::setTextColor(Constants::DEFAULT_COLOR);
    cout << Language::TYPE_ENGLISH_WORD_OR_INDEX_UPDATE;
    GetLine(cin, en, Constants::ENG_COLOR);
    int index = 0;
    if (IntergerParser::TryParse(en, index)) {
        Word word = _dictionary.find(index);
        if(word == Word::NOT_FOUND){
            Console::setTextColor(Constants::FAILED_COLOR);
            cout << Language::NOT_FOUND_WORD << endl;
            pressAnyContinue();
        	return;
        }
        Console::setTextColor(Constants::DEFAULT_COLOR);
        cout << Language::UPDATE_WORD;
        Console::setTextColor(Constants::ENG_COLOR);
        cout << word.getEng();
        Console::setTextColor(Constants::DEFAULT_COLOR);
        cout << ": " << endl;
        cout <<  Language::TYPE_VIETNAMESE_WORD;
        GetLine(cin, vi, Constants::VIET_COLOR);
        word.setViet(vi);
        _dictionary.addOrUpdate(word);
        Console::setTextColor(Constants::SUCCESS_COLOR);
        cout <<  Language::UPDATE_WORD_SUCCESS << endl;
    } else {
        if (_dictionary.find(en) == Word::NOT_FOUND) {
            Console::setTextColor(Constants::DEFAULT_COLOR);
            cout << Language::TYPE_VIETNAMESE_WORD;
            GetLine(cin, vi, Constants::VIET_COLOR);
            _dictionary.addOrUpdate(en, vi);
            Console::setTextColor(Constants::SUCCESS_COLOR);
            cout << Language::UPDATE_WORD_SUCCESS << endl;
        } else {
            Console::setTextColor(Constants::FAILED_COLOR);
            cout << Language::NOT_FOUND_WORD_TO_UPDATE << endl;
        }
    }
    pressAnyContinue();
}

void Program::findWords() {
    Console::clear();
    Console::setTextColor(Constants::HEADER_MENU);
    cout << "***" <<Language::MENU_FIND_WORD << "***" << endl;

    string en;
    Console::setTextColor(Constants::DEFAULT_COLOR);
    cout << Language::TYPE_ENGLISH_WORD;
    GetLine(cin, en, Constants::ENG_COLOR);
    const Word word = _dictionary.find(en);
    if (word != Word::NOT_FOUND)
        cout << word << endl;
    else{
        Console::setTextColor(Constants::FAILED_COLOR);
        cout << Language::NOT_FOUND_WORD<< endl;
    }
    pressAnyContinue();
}

void Program::findWords(int index) {
    Console::clear();
    const Word word = _dictionary.find(index);
    if (word != Word::NOT_FOUND)
        cout << word << endl;
    else{
        Console::setTextColor(Constants::FAILED_COLOR);
        cout << Language::NOT_FOUND_WORD << endl;
    }
}

void Program::allWords() {
    Console::clear();
    Console::setTextColor(Constants::HEADER_MENU);
    cout << "***" <<Language::MENU_ALL_WORD << "***" << endl;
    Console::setTextColor(Constants::DEFAULT_COLOR);
    cout << "************************" << endl;
    _dictionary.forEach(printWord);
    Console::setTextColor(Constants::DEFAULT_COLOR);
    cout << "************************" << endl;
    pressAnyContinue();
}

void Program::removeWords() {
    Console::clear();
    Console::setTextColor(Constants::HEADER_MENU);
    cout << "***" <<Language::MENU_REMOVE_WORD << "***" << endl;

    string en;
    int index = 0;
    Console::setTextColor(Constants::DEFAULT_COLOR);
    cout << Language::TYPE_ENGLISH_WORD_OR_INDEX_REMOVE;
    Console::setTextColor(Constants::ENG_COLOR);
    GetLine(cin, en, Constants::ENG_COLOR);
     if (IntergerParser::TryParse(en, index)){
     	Word word = _dictionary.find(index);
        if(word == Word::NOT_FOUND){
            Console::setTextColor(Constants::FAILED_COLOR);
            cout << Language::NOT_FOUND_WORD << endl;
            pressAnyContinue();
        	return;
		}
        _dictionary.remove(word.getEng());
        Console::setTextColor(Constants::SUCCESS_COLOR);
		cout << Language::REMOVE_WORD_SUCCESS << endl;
	 }else{
    	if (_dictionary.find(en) == Word::NOT_FOUND) {
            Console::setTextColor(Constants::FAILED_COLOR);
        cout << Language::NOT_FOUND_WORD_TO_REMOVE << endl;
    	} else {
        _dictionary.remove(en);
        Console::setTextColor(Constants::SUCCESS_COLOR);
        cout << Language::REMOVE_WORD_SUCCESS << endl;
        }
        pressAnyContinue();
	}  
}

void Program::run() {
    _menu.excute();
}

void Program::exit() {
    SaveDataToFile();
    ::exit(0);
}
void Program::pressAnyContinue() {
    Console::setTextColor(Constants::HEADER_MENU);
    cout << Language::TYPE_ANY_CONTINUE;
    getch();
    Console::clear();
}

Program::~Program() {
}
