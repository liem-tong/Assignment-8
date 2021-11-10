// Liem Tong
// Z1790591
// CSC 340 PE1
//
// I certify that this is my own work and where appropriate an extension
// of the starter code provided for the assignment.

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "node.h"
#include "btree.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    void Insert(const T &x);       // inserts node with value x
    bool Search(const T &x) const; // searches leaf with value x
    bool Remove(const T &x);       // removes leaf with value x
private:
    void _Insert(Node<T> *&node, const T &x);      // private version of insert
    bool _Search(Node<T> *node, const T &x) const; // private version of search
    void _Remove(Node<T> *&node, const T &x);      // private version of remove
    bool _Leaf(Node<T> *node) const;          // checks if node is leaf
};

// function to call the private version of insert
template <typename T>
void BinarySearchTree<T>::Insert(const T &x) {
    _Insert(this->root, x);
}

// function to call the private version of search
template <typename T>
bool BinarySearchTree<T>::Search(const T &x) const {
    return _Search(this->root, x);
}

// function to call the private verison of remove
template <typename T>
bool BinarySearchTree<T>::Remove(const T &x) {
    _Remove(this->root, x);
    return true;
}

// private functions
template <typename T>
void BinarySearchTree<T>::_Insert(Node<T> *&node, const T &x) {
    // do nothing if there is value in node
    if (x == node->data) return;

    // compare node, if less than more than current node then insert left node
    if (x < node->data) _Insert(node->left, x);

    // otherwise insert right node
    else _Insert(node->right, x);
}

template <typename T>
bool BinarySearchTree<T>::_Search(Node<T> *node, const T &x) const {
    // search for value
    if (node == nullptr) return false;
    else if (x == node->data) return true;

    // if value is bigger than node data
    else if (x > node->data) _Search(node->right, x);

    // otherwise if smaller
    else _Search(node->left, x);
}

template <typename T>
void BinarySearchTree<T>::_Remove(Node<T> *&node, const T &x) {
    // base case
    if (node == NULL) return;

    // if data is greater than current value, delete
    if (x < node->data) _Remove(node->left, x);

    // if data is smaller than current value, delete.
    else if (x > node->data) _Remove(node->right, x);
    else {
        // if one of the node is empty
        if (node->left == NULL && node->right == NULL) delete node;
        else if (node->left == NULL) {
            Node<T> *temp = node->right;
            node->data = temp->data;
            node->right = temp->right;
            temp = nullptr;
            delete temp;
        }
        else if (node->right == NULL) {
            Node<T> *temp = node->left;
            node->data = temp->data;
            node->left = temp->left;
            temp = nullptr;
            delete temp;
        }
    }
}

// check if node is a leaf
template <typename T>
bool BinarySearchTree<T>::_Leaf(Node<T> *node) const {
    if (node == nullptr) return false;
    if (node->left == nullptr && node->right == nullptr) return true;
    return false;
}

#endif // End of BINARYSEARCHTREE_H_
