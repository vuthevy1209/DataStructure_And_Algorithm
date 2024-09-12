#pragma once
#include <iostream>
#include <utility>  // for std::exchange, std::swap

template<class T>
struct Queue {
private:
    struct Node {  // inner class
        T data;
        Node* next;
    };

    Node* _front = nullptr;
    Node* _back = nullptr;
    size_t m_size = 0;

public:
    Queue() = default;

    // rule of five - no copying, only moving allowed
    Queue(const Queue&) = delete;
    Queue(Queue&& rhs) noexcept :
        _front(std::exchange(rhs._front, nullptr)),
        _back(std::exchange(rhs._back, nullptr)),
        m_size(rhs.m_size)
    {}
    Queue& operator=(const Queue&) = delete;
    Queue& operator=(Queue&& rhs) noexcept {
        std::swap(_front, rhs._front);
        std::swap(_back, rhs._back);
        m_size = rhs.m_size;
        return *this;
    }
    ~Queue() {
        while (_front) {
            delete std::exchange(_front, _front->next);
        }
    }

    bool empty() const { return m_size == 0; }
    size_t size() const { return m_size; }

    void push(const T& data) {
        Node* newNode = new Node{ data, nullptr };
        if (_back) {
            _back->next = newNode;
        }
        else {
            _front = newNode;
        }
        _back = newNode;
        ++m_size;
    }

    T pop() {
        if (empty()) throw std::out_of_range("Queue is empty");
        T rv = std::move(_front->data);
        Node* temp = _front;
        _front = _front->next; 
        delete temp;
        if (!_front) {
            _back = nullptr;
        }
        --m_size;
        return rv;
    }

    const T& front() const {
        if (empty()) throw std::out_of_range("Queue is empty");
        return _front->data; 
    }
};


