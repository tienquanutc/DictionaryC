#include "Word.h"

Word const Word::NOT_FOUND = Word("", "");

Word::Word(const string& key, const string& value)
	: _en(key), _vi(value) {}

Word::Word(const string& key)
	: _en(key), _vi("") {}

string Word::getEng() const { return _en; }
void Word::setEng(const string& en) { _en = en; }
string Word::getViet() const { return _vi; }
void Word::setViet(const string& vi) { _vi = vi; }

bool operator==(const Word& lhs, const Word& rhs) {
	return lhs._en == rhs._en;
}

bool operator!=(const Word& lhs, const Word& rhs) {
	return !(lhs == rhs);
}

bool operator<(const Word& lhs, const Word& rhs) {
	return lhs._en < rhs._en;
}

bool operator<=(const Word& lhs, const Word& rhs) {
	return !(rhs < lhs);
}

bool operator>(const Word& lhs, const Word& rhs) {
	return rhs < lhs;
}

bool operator>=(const Word& lhs, const Word& rhs) {
	return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream& os, const Word& obj) {
	if (typeid(os) == typeid(std::cout)) {
		Console::setTextColor(Constants::ENG_COLOR);
		os << left << setw(Constants::WIDTH_WORD) << obj._en;
		Console::setTextColor(Constants::VIET_COLOR);
		os << setw(Constants::WIDTH_WORD) << obj._vi << endl << right;
		Console::setTextColor(Constants::DEFAULT_COLOR);
		return os;
	}
	return os << obj._en << endl << obj._vi;
}

std::istream& operator>>(std::istream& is, Word& obj) {
	getline(is, obj._en);
	getline(is, obj._vi);
	return is;
}
