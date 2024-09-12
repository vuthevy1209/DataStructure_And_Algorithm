template <class T>
bool queue<T>::empty() {
    return head == nullptr;
}

template <class T>
node<T>* create_node(T value){
    node<T>* newnode = new (nothrow) node<T>;
    if(newnode == nullptr){return nullptr;}
    newnode->data = value;
    newnode->next = nullptr;
    return newnode;
}

template <class T>
void queue<T>::push(T value){
    node<T>* newnode = create_node(value);
    if(newnode == nullptr) return;
    if(head == nullptr) head = newnode;
    else{
        node<T>* temp = head;
        while(temp->next != nullptr) temp = temp->next;
        temp->next = newnode;
    }
}

template <class T>
void queue<T>::pop(){
    if(head == nullptr) return;
    else{
        node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}


template <class T>
T queue<T>::front(){
    if(head == nullptr) return T();
    else return head->data;
}


