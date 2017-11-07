#ifndef _PROGRAM_H_
#define _PROGRAM_H_ 

#include <functional>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include "../Menu/Menu.h"
#include "../Dictionary/Dictionary.h"
#include "../Utils/Console.h"
#include "../Resources/Language.h"


class Program
{
private:
	Menu<Program> _menu;
	Dictionary _dictionary;

	void initMenu();
	void Initialize();
	void LoadDataFromFile();
	static void printWord(int index, const Word& word);
public:
	Program();

	void findApproximately();
	void addWords();
	void findWords();
	void findWords(int index);
	void allWords();
	void updateWords();
	void removeWords();
	void exit() ;

	void SaveDataToFile();
	void run();
	
	void pressAnyContinue();

	~Program();
//drawing
};

#endif
