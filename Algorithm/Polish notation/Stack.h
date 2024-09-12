#pragma once
#include<iostream>
#include<utility>

template<class T>
struct Stack {
private:
    struct Node {  
        T data;
        Node* next;
    };

    Node* _top = nullptr;
    size_t m_size = 0;

public:
    Stack() = default;
    Stack(const Stack&) = delete;
    Stack(Stack&& rhs) noexcept :
        _top(std::exchange(rhs._top, nullptr)), m_size(rhs.m_size)
    {}
    Stack& operator=(const Stack&) = delete;
    Stack& operator=(Stack&& rhs) noexcept {
        std::swap(_top, rhs._top);
        m_size = rhs.m_size;
        return *this;
    }
    ~Stack() {
        while (_top) {
            delete std::exchange(_top, _top->next);
        }
    }

    bool empty() const { return m_size == 0; }
    size_t size() const { return m_size; }

    void push(const T& data) {
        _top = new Node{ data, _top };
        ++m_size;
    }

    T pop() {
        if (empty()) throw std::out_of_range("Stack is empty");
        T rv = std::move(_top->data);
        delete std::exchange(_top, _top->next);
        --m_size;
        return rv;
    }

    const T& top() const {
        if (empty()) throw std::out_of_range("Stack is empty");
        return _top->data; 
    }
};
