#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

enum Color { RED, BLACK };

template <class T>
struct node{
    T data;
    Color color;
    node* left;
    node* right;
    node* parent;
};

template <class T>
class RBTree{
private:
    node<T>* root;
    node<T>* NIL;

    void remove_all(node<T>* virtual_root){
        if(virtual_root != NIL){
            remove_all(virtual_root->left);
            remove_all(virtual_root->right);
            delete virtual_root;
        }
    }

    node<T>* create_node(T value);
    node<T>* SEARCH(node<T>* virtual_root, T value);
    node<T>* minimum(node<T>* virtual_root);
    void left_rotate(node<T>* x);
    void right_rotate(node<T>* x);
    void insert_fixup(node<T>* z);
    void delete_fixup(node<T>* x);
    void transplant(node<T>* u, node<T>* v);

public:
    RBTree(){
        NIL = new node<T>;
        NIL->color = BLACK;
        NIL->left = NIL;
        NIL->right = NIL;
        NIL->parent = NIL;
        root = NIL;
    }
    ~RBTree(){
        remove_all(root);
        delete NIL;
        root = nullptr;
        NIL = nullptr;
    }

    bool empty(){
        return root == NIL;
    }
    void insert(T value);
    void erase(T value);
    node<T>* search(T value){
        node<T>* it = SEARCH(root, value);
        return (it == NIL) ? nullptr : it;
    }
    node<T>* get_root(){
        return (root == NIL) ? nullptr : root;
    }
    node<T>* get_nil(){
        return NIL;
    }
};

#include "RBTree.inl"
