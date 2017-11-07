#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_ 

#include <vector>
#include <ostream>
#include "Word.h"
#include "../BinaryTree/BST.h"
#include "../Resources/Language.h"

class Dictionary
{
private:
	BST<Word> _source;
public:
	void addOrUpdate(const string& en, const string& vi);
	void addOrUpdate(const Word& word);
	void remove(const string& en);
	void remove(const Word& word);
	Word find(const string& en);
	Word find(int index);
	vector<Word> findApproximately(const string& en);
	void forEach(void(*callback)(int index, const Word& word)) const;
	int numOfWords() const;
	BST<Word>& getSource();

	friend std::ostream& operator<<(std::ostream& os, const Dictionary& dictionary);
	friend  std::istream& operator>>(std::istream& is, Dictionary& dictionary);
};

#endif