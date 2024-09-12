#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

template <class T>
struct node{
    T data;
    node* next;
};

template <class T>
class stack{
private:
    node<T>* head;
public:
    stack(){head = nullptr;}
    ~stack(){
        while(head != nullptr){
            node<T>* temp = head;
            head = head->next;
            delete temp; 
        }
        head = nullptr;
    }
    bool empty();
    void push(T value);
    void pop();
    T top();
};

#include "Stack.inl"