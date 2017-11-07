#ifndef _BST_ITERATOR_H
#define _BST_ITERATOR_H 
#include <stack>
#include "BST.h"
#include "BSTNode.h"

using namespace std;

template <class T>
class BSTIterator {
private:
    stack<BSTNode<T>*> stack;

public:
    BSTIterator<T>(BSTNode<T>* root) {
        if (root == nullptr)
            return;
        stack.push(root);
        while (root->getLeft() != nullptr) {
            stack.push(root->getLeft());
            root = root->getLeft();
        }
    }

    bool hasNext();
    BSTNode<T>* next();
};

template <class T>
bool BSTIterator<T>::hasNext() {
    return stack.size() > 0;
}

template <class T>
BSTNode<T>* BSTIterator<T>::next() {
    BSTNode<T>* node = stack.top();
    stack.pop();
    if (node->getRight() != nullptr) {
        BSTNode<T>* nodeTemp = node->getRight();
        stack.push(nodeTemp);
        while (nodeTemp->getLeft() != nullptr) {
            stack.push(nodeTemp->getLeft());
            nodeTemp = nodeTemp->getLeft();
        }
    }
    return node;
}

#endif
