#ifndef _BST_NODE_H_
#define _BST_NODE_H_ 

#include "BST.h"

template <class T>
class BSTNode {
	template<class Type> friend class BST;
protected:
	T data;
	BSTNode<T>* left;
	BSTNode<T>* right;
public:
	BSTNode<T>(T data, BSTNode<T>* left, BSTNode<T>* right);
	BSTNode<T>(T data);

	T getData();
	void setData(const T& data);
	BSTNode<T>* getLeft();
	void setLeft(BSTNode<T>* left);
	BSTNode<T>* getRight();
	void setRight(BSTNode<T>* right);
	~BSTNode<T>();
};

template <class T>
BSTNode<T>::BSTNode(T data, BSTNode<T>* left, BSTNode<T>* right)
: data(data), left(left), right(right){
}

template <class T>
BSTNode<T>::BSTNode(T data):
BSTNode(data, nullptr, nullptr){
	
}

template <class T>
T BSTNode<T>::getData() {
	return data;
}

template <class T>
void BSTNode<T>::setData(const T& data) {
	this->data = data;
}


template <class T>
BSTNode<T>* BSTNode<T>::getLeft() {
	return this->left;
}

template <class T>
void BSTNode<T>::setLeft(BSTNode<T>* left) {
	this->left = left;
}

template <class T>
BSTNode<T>* BSTNode<T>::getRight() {
	return this->right;
}

template <class T>
void BSTNode<T>::setRight(BSTNode<T>* right) {
	this->right = right;
}

template <class T>
BSTNode<T>::~BSTNode() {
	
}

#endif
