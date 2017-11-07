#ifndef _WORD_H_
#define _WORD_H_ 

#include <string>
#include <ostream>
#include <iostream>
#include <iomanip>
#include <typeinfo>
#include "../Utils/GetString.h"
#include "../Utils/Console.h"
#include "../Resources/Constants.h"

using namespace std;

class Word {
private:
	string _en;
	string _vi;
public:
	static const Word NOT_FOUND;

	Word(const string& en, const string& vi);
	Word(const string& en);

	string getEng() const;
	void setEng(const string& en);
	string getViet() const;
	void setViet(const string& vi);

	friend bool operator==(const Word& lhs, const Word& rhs);
	friend bool operator!=(const Word& lhs, const Word& rhs);
	friend bool operator<(const Word& lhs, const Word& rhs);
	friend bool operator<=(const Word& lhs, const Word& rhs);
	friend bool operator>(const Word& lhs, const Word& rhs);
	friend bool operator>=(const Word& lhs, const Word& rhs);

	friend std::ostream& operator<<(std::ostream& os, const Word& word);

	friend std::istream& operator>>(std::istream& is, Word& word);
};

#endif
