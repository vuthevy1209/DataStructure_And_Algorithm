#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <class T>
class Heap{
private:
    vector<T> data;
    bool (*cmp)(T, T);

    void heapify_up(int idx);
    void heapify_down(int idx);

public:
    Heap(bool (*cmp_func)(T, T)) : cmp(cmp_func) {}
    Heap(T* arr, int n, bool (*cmp_func)(T, T)) : cmp(cmp_func){
        build(arr, n);
    }

    bool empty();
    int size();
    T top();
    void push(T value);
    void pop();
    void build(T* arr, int n);
};

#include "Heap.inl"
