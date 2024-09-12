#include <iostream>
#include <cstring>
#include <vector>
#include "set"
#include <sstream>
#include "math.h"
#include "queue"
#include "algorithm"
#include <stack>
#include "fstream"
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    int height;
};

node *create_node(int x){
    node *newnode = new node;
    newnode->data = x;
    newnode->left = newnode->right = nullptr;
    newnode->height = 0;
    return newnode;
}

int height(node *t){
    if (t == nullptr)
        return -1;
    else
        return t->height;
}

void Left_Left(node *&k){
    node *k1 = k->left;
    k->left = k1->right;
    k1->right = k;
    k->height = max(height(k->left), height(k->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k = k1;
}

void Right_Right(node *&k){
    node *k1 = k->right;
    k->right = k1->left;
    k1->left = k;
    k->height = max(height(k->left), height(k->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k = k1;
}

void Left_Right(node *&k){
    Right_Right(k->left);
    Left_Left(k);
}

void Right_Left(node *&k){
    Left_Left(k->right);
    Right_Right(k);
}

void balance(node *&k){
    if (k == nullptr)
        return;
    if (height(k->left) - height(k->right) > 1){
        if (height(k->left->left) >= height(k->left->right))
            Left_Left(k);
        else
            Left_Right(k);
    }
    else if (height(k->right) - height(k->left) > 1){
        if (height(k->right->right) >= height(k->right->left))
            Right_Right(k);
        else
            Right_Left(k);
    }
    k->height = max(height(k->left), height(k->right)) + 1;
}

void push(node *&root, int x) {
    node *newnode = create_node(x);
    if (root == nullptr) {
        root = newnode;
        return;
    }
    node *current = root;
    node *parent = nullptr;
    while (true) {
        parent = current;
        if (x < current->data) {
            current = current->left;
            if (current == nullptr) {
                parent->left = newnode;
                break;
            }
        } else if (x > current->data) {
            current = current->right;
            if (current == nullptr) {
                parent->right = newnode;
                break;
            }
        } else {
            // root->data = x
            delete newnode;
            break;
        }
    }
    balance(root);
}


void pop(node *&root, int x) {
    node *parent = nullptr;
    node *current = root;
    while (current != nullptr && current->data != x) {
        parent = current;
        if (x < current->data){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    if (current == nullptr)
        return;

    if (current->left == nullptr && current->right == nullptr) {
        if (current != root) {
            if (parent->left == current)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        } else {
            root = nullptr;
        }
        delete current;
    } else if (current->left != nullptr && current->right != nullptr) {
        node *successor = current->right;
        node *succParent = current;
        while (successor->left != nullptr) {
            succParent = successor;
            successor = successor->left;
        }
        current->data = successor->data;
        if (succParent->left == successor)
            succParent->left = successor->right;
        else
            succParent->right = successor->right;
        delete successor;
        
    } else {
        node *child = nullptr;
        if(current->left != nullptr){
            child = current->left;
        }
        else {
            child = current->right;
        }

        if (current != root) {
            if (current == parent->left)
                parent->left = child;
            else
                parent->right = child;
        } else {
            root = child;
        }
        delete current;
    }
    balance(root);
}

void LNR(node *root) {
    stack<node *> s;
    node *current = root;
    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
    }
}
