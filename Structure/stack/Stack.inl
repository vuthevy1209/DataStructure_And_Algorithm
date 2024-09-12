template <class T>
bool stack<T>::empty() {
    return head == nullptr;
}


template <class T>
node<T>* create_node(T value){
    node<T>* newnode = new (nothrow) node<T>;
    if(newnode ==  nullptr){return nullptr;}
    newnode->data = value;
    newnode->next = nullptr;
    return newnode;
}

template <class T>
void stack<T>::push(T value){
    node<T>* newnode = create_node(value);
    if(newnode == nullptr) return;
    if(head == nullptr) head = newnode;
    else{
        newnode->next = head;
        head = newnode;
    }
}

template <class T>
void stack<T>::pop(){
    if(head == nullptr) return;
    else{
        node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}


template <class T>
T stack<T>::top() {
    if (empty()) return T(); 
    return head->data;
}



