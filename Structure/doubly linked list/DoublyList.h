#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;

template <class T>
struct node{
    T data;
    node* next;
    node* prev;
};

template <class T>
class doubly_list{
private:
    node<T>* head;
    node<T>* tail;
    int n_size;
public:
    doubly_list(): head(nullptr), tail(nullptr), n_size(0){}
    ~doubly_list(){
        while(head != nullptr){
            node<T>* temp = head;
            head = head->next;
            delete temp; 
        }
        head = nullptr;
        tail = nullptr;
    }
    bool empty();
    int size();
    node<T>* begin();
    node<T>* end();
    void push_front(T value);
    void push_back(T value);
    void pop_front();
    void pop_back();
    void insert_at_location(int location, T value);
    void insert_after_key_value(T key, T value);
    void insert_before_key_value(T key, T value);
    void erase(T value);
    void erase_at_location(int location);
    node<T>* find(T value);
    void sort(bool (*cmp) (T, T));
    void reverse();
};

#include "DoublyList.inl"