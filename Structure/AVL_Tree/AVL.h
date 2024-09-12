#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

template <class T>
struct node{
    T data;
    node* left;
    node* right;
    int height;
};


template <class T>
class AVL{
private:
    node<T>* root;

    void remove_all(node<T>* virtual_root){
        if(virtual_root != nullptr){
            remove_all(virtual_root->left);
            remove_all(virtual_root->right);
            delete virtual_root;
            virtual_root = nullptr;
        }
    }
    node<T>* create_node(T value);
    void INSERT(node<T>* &virtual_root, T value);
    void ERASE(node<T>* &virtual_root, T value);
    node<T>* SEARCH(node<T>* virtual_root, T value);

    int height(node<T> *t);
    void Left_Left(node<T> *&k);
    void Right_Right(node<T> *&k);
    void Left_Right(node<T> *&k);
    void Right_Left(node<T> *&k);
    void balance(node<T> *&k);

public:
    AVL(): root(nullptr){}
    ~AVL(){
        remove_all(root);
    }
    bool empty();
    void insert(T value);
    void erase(T value);
    node<T>* search(T value);
    node<T>* get_root();
};

#include "AVL.inl"


