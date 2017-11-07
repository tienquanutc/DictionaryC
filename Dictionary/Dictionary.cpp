#include "Dictionary.h"

void Dictionary::addOrUpdate(const string& en, const string& vi) {
    addOrUpdate(Word(en, vi));
}

void Dictionary::addOrUpdate(const Word& word) {
    BSTNode<Word>* node = _source.find(word);
    if (node == nullptr)
        return _source.add(word);
    return node->setData(word);
}
void Dictionary::remove(const string& en) {
    remove(Word(en));
}
void Dictionary::remove(const Word& word) {
    _source.remove(word);
}

Word Dictionary::find(const string& en) {
    const Word word(en);
    BSTNode<Word>* result = _source.find(word);
    if (result != nullptr)
        return result->getData();
    return Word::NOT_FOUND;
}
Word Dictionary::find(int index) {
    BSTIterator<Word> iter = _source.getIterator();
    int i = 1;
    if (index <= 0)
        return Word::NOT_FOUND;
    while (iter.hasNext()) {
        if (i == index){
        	cout << "found " << endl;
        	//cout << iter.next()->getData().getEng() << " " << iter.next()->getData().getViet() << endl;
            return iter.next()->getData();
		}
		iter.next();
        i++;
    }
    return Word::NOT_FOUND;
}

vector<Word> Dictionary::findApproximately(const string& en) {
    BSTIterator<Word> iter = _source.getIterator();
    vector<Word> result;
    while (iter.hasNext()) {
        Word current = iter.next()->getData();
        if (current.getEng().find(en) != string::npos)
            result.push_back(current);
    }
    return result;
}

void Dictionary::forEach(void (*callback)(int index, const Word& word)) const {
    BSTIterator<Word> iter = _source.getIterator();
    int index              = 0;
    while (iter.hasNext()) {
        const Word current = iter.next()->getData();
        callback(++index, current);
    }
}

int Dictionary::numOfWords() const {
    return _source.size();
}

BST<Word>& Dictionary::getSource() {
    return _source;
}


std::ostream& operator<<(std::ostream& os, const Dictionary& dictionary) {
	BSTIterator<Word> iter = dictionary._source.getIterator();
	while (iter.hasNext()) {
		const Word word = iter.next()->getData();
		os << word << endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Dictionary& dictionary){
	Word word("", "");
	while (!is.eof()) {
		is >> word;
		if(word != Word::NOT_FOUND)
			dictionary._source.add(word);
	}
	return is;
}
