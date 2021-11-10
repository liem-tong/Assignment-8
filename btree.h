// Liem Tong
// Z1790591
// CSC 340 PE1
//
// I certify that this is my own work and where appropriate an extension
// of the starter code provided for the assignment.

#ifndef H_BTREE
#define H_BTREE

#include "node.h"
#include <stdlib.h>
#include <time.h>

typedef enum {left_side, right_side } SIDE;
SIDE rnd(){
    return rand()%2 ? right_side : left_side;
}// End of rnd()

template <typename T> class BinaryTree{

public:
    BinaryTree();                                      // default constructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns height of tree
    virtual void Insert(const T& temp);                     // inserts node in tree
    void         Inorder(void (*print)(const T&));          // inorder traversal of tree

protected:
    Node<T> *root;                                      // root of tree

private:
    unsigned _getSize(Node<T> *node) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *node) const;               // private version of getHeight()
    void     _Insert(Node<T> *&node, const T& temp);             // private version of Insert()
    void     _Inorder(Node<T> *node, void (*print)(const T&));   // private version of Inorder()
};

// public member functions
// default constructor
template <typename T>
BinaryTree<T>::BinaryTree() {
    root = 0;
}

// function to call private member to return the size of tree
template <typename T>
unsigned BinaryTree<T>::getSize() const {
    return _getSize(root);
}

// function to call private member to return the height of tree
template <typename T>
unsigned BinaryTree<T>::getHeight() const {
    return _getHeight(root);
}

// function to call private member to insert data to node of tree
template <typename T>
void BinaryTree<T>::Insert(const T& temp) {
    _Insert(root, temp);
}

// function to call private member to print tree in order
template <typename T>
void BinaryTree<T>::Inorder(void (*print)(const T&)) {
    _Inorder(root, print);
}

// private member functions
// function to get size of the tree
template <typename T>
unsigned BinaryTree<T>::_getSize(Node<T> *node) const {

    // if node has no data, the size will be zero
    if (node == NULL) return 0;

    // return the number of nodes on the left and right plus the root
    else return (_getSize(node->left) + 1 + _getSize(node->right));
}

// function to get height of the tree
template <typename T>
unsigned BinaryTree<T>::_getHeight(Node<T> *node) const {

    // if node is there, count as height 1
    if (node == NULL) return 1;
    else {
        // define the height on the left
        unsigned heightLeft = _getHeight(node->left);

        // define the height on the right
        unsigned heightRight = _getHeight(node->right);

        // compare the two sides of the tree, if higher, then take that height plus the height of root
        if (heightLeft > heightRight) return (heightLeft + 1);
        else return (heightRight + 1);
    }
}

// function to fill in data for each node
template <typename T>
void BinaryTree<T>::_Insert(Node<T> *&node, const T& temp) {

    // define the node for each side and data for each node
    if (node == NULL) {
        node = new Node<T>();
        node->right = NULL;
        node->left = NULL;
        node->data = temp;

      // filling data to nodes on each side
    } else if (rnd() == right_side) _Insert(node->right, temp);
    else _Insert(node->left, temp);
}

// function to print datas on each node
template <typename T>
void BinaryTree<T>::_Inorder(Node<T> *node, void (*print)(const T&)) {

    // print data of each node on each side
    if (node != NULL) {
        _Inorder(node->left, print);
        print(node->data);
        _Inorder(node->right, print);
    }
}
#endif // End of H_BTREE
