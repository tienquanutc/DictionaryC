#ifndef _BST_H_
#define _BST_H_ 

#include <vector>
#include "BSTIterator.h"
#include "BSTNode.h"

using namespace std;

template <class T>
class BST {
protected:
    BSTNode<T>* root;
    int numNode;

private:
    void preOder(BSTNode<T>* p, const void (*visit)(BSTNode<T>*));
    void inOder(BSTNode<T>* p, const void (*visit)(BSTNode<T>*));
    void postOder(BSTNode<T>* p, const void (*visit)(BSTNode<T>*));
    void destroyRecursive(BSTNode<T>* &node);
public:
    BST<T>();
    void add(T data);
    void remove(T data);
    BSTNode<T>* find(const T& data);
    bool isEmpty();
    int size() const;
    BSTNode<T>* getRoot();

    void preOder(const void (*visit)(BSTNode<T>*));
    void inOder(const void (*visit)(BSTNode<T>*));
    void postOder(const void (*visit)(BSTNode<T>*));

    BSTIterator<T> getIterator() const;

    ~BST<T>();
};

template <class T>
void BST<T>::preOder(BSTNode<T>* p, const void (*visit)(BSTNode<T>*)) {
    if (p != nullptr) {
        visit(p);
        preOder(p->left, visit);
        preOder(p->right, visit);
    }
}

template <class T>
void BST<T>::inOder(BSTNode<T>* p, const void (*visit)(BSTNode<T>*)) {
    if (p != nullptr) {
        inOder(p->left, visit);
        visit(p);
        inOder(p->right, visit);
    }
}

template <class T>
void BST<T>::postOder(BSTNode<T>* p, const void (*visit)(BSTNode<T>*)) {
    if (p != nullptr) {
        postOder(p->left, visit);
        postOder(p->right, visit);
        visit(p);
    }
}

 template <class T>
 void BST<T>::destroyRecursive(BSTNode<T>* &node) {
 	if (node)
    {
        destroyRecursive(node->left);
        destroyRecursive(node->right);
        delete node;
        node = nullptr;
    }
 }

template <class T>
BST<T>::BST() {
    this->root = nullptr;
    numNode    = 0;
}

template <class T>
void BST<T>::add(T data) {
    BSTNode<T>*prev = nullptr, *p = root;
    while (p != nullptr) {
        prev = p;
        if (data < p->data)
            p = p->left;
        else
            p = p->right;
    }
    if (prev == nullptr)
        root = new BSTNode<T>(data);
    else if (data < prev->data)
        prev->left = new BSTNode<T>(data);
    else
        prev->right = new BSTNode<T>(data);

    numNode++;
}

template <class T>
void BST<T>::remove(T data) {
    BSTNode<T>*p = root, *prev = p;
    while (p != nullptr && p->data != data) {
        prev = p;
        p    = (data < p->data) ? p->left : p->right;
    }
    if (p != nullptr && p->data == data) {
        BSTNode<T>* t = p;
        if (t->right == nullptr)
            t = t->left;
        else if (t->left == nullptr)
            t = t->right;
        else {
            BSTNode<T>* tmp = t->left;
            while (tmp->right != nullptr) {
                tmp = tmp->right;
            }
            tmp->right = t->right;
            t          = t->left;
        }
        if (p == root)
            root = t;
        else if (prev->left == p)
            prev->left = t;
        else
            prev->right = t;

        delete p;

        numNode--;
    }
    // else
    // TODO: implement case notfound here! ?? not need!
}

template <class T>
BSTNode<T>* BST<T>::find(const T& data) {
    BSTNode<T>* p = root;
    while (p != nullptr && p->data != data) {
        p = (data < p->data) ? p->left : p->right;
    }
    return p;
}

template <class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}

template <class T>
int BST<T>::size() const {
    return numNode;
}

template <class T>
BSTNode<T>* BST<T>::getRoot() {
    return root;
}

template <class T>
void BST<T>::preOder(const void (*visit)(BSTNode<T>*)) {
    preOder(root, visit);
}

template <class T>
void BST<T>::inOder(const void (*visit)(BSTNode<T>*)) {
    inOder(root, visit);
}

template <class T>
void BST<T>::postOder(const void (*visit)(BSTNode<T>*)) {
    postOder(root, visit);
}

template <class T>
BSTIterator<T> BST<T>::getIterator() const {
    return BSTIterator<T>(root);
}

template <class T>
BST<T>::~BST() {
	destroyRecursive(this->root);
}

#endif
