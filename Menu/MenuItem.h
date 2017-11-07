#ifndef _MENU_ITEM_H_
#define _MENU_ITEM_H_ 

#include <iostream>
#include <string>
#include <ostream>
#include <functional>

using namespace std;

template <class T>
class MenuItem {
	typedef void(T::*Action)();
private:
	T* _pT;
	Action _action;
	string _name;
public:
	MenuItem( T* pT, const Action action, const string& name);
	void excute() const;
	string getName() const;

	friend std::ostream& operator<<(std::ostream& os, const MenuItem& obj) {
		os << obj._name;
		return os;
	}
};

template <class T>
MenuItem<T>::MenuItem(T* pT, const Action action, const string& name)
: _pT(pT), _action(action), _name(name) {
}

template <class T>
void MenuItem<T>::excute() const {
	std::bind(_action, _pT)();
}

template <class T>
string MenuItem<T>::getName() const {
	return _name;
}

#endif
