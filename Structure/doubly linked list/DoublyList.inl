template <class T>
int doubly_list<T>::size(){
    return n_size;
}

template <class T>
node<T>* doubly_list<T>::begin(){
    if (head == nullptr) return nullptr;
    else return head;
}

template <class T>
node<T>* doubly_list<T>::end(){
    if (head == nullptr) return nullptr;
    else return tail;
}

template <class T>
bool doubly_list<T>::empty(){
    return head == nullptr;
}

template <class T>
node<T>* create_node(T value){
    node<T>* newnode = new (nothrow) node<T>;
    if(newnode ==  nullptr){return nullptr;}
    newnode->data = value;
    newnode->next = nullptr;
    newnode->prev = nullptr;
    return newnode;
}

template <class T>
void doubly_list<T>::push_front(T value){
    node<T>* newnode = create_node(value);
    if(newnode == nullptr) return;
    if(head == nullptr) head = tail = newnode;
    else{
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    n_size++;
}

template <class T>
void doubly_list<T>::push_back(T value){
    node<T>* newnode = create_node(value);
    if(newnode == nullptr) return;
    if(head == nullptr) head = tail = newnode;
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    n_size++;
}

template <class T>
void doubly_list<T>::pop_front(){
    if(head == nullptr) return;
    if(head -> next == nullptr){
        node<T>* delete_node = head;
        head = tail = nullptr;
        delete delete_node;
        n_size--;
        return;
    }
    node<T>* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    n_size--;
}

template <class T>
void doubly_list<T>::pop_back(){
    if(head == nullptr) return;
    if(head->next == nullptr){
         pop_front();
         return;
    }
    node<T>* delete_node = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete delete_node;
    n_size--;
}

template <class T>
void doubly_list<T>::insert_at_location(int location, T value){
    if(location < 1 || location > n_size + 1) return;
    if(location == 1){
         push_front(value);
         return;
    }
    if(location == n_size + 1){
         push_back(value);
         return;
    }
    node<T>* newnode = create_node(value);
    if(newnode == nullptr) return;
    node<T>* temp = head;
    for(int i = 1; i <= location-2; i++) temp = temp->next;
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
    n_size++;
}

template <class T>
void doubly_list<T>::insert_after_key_value(T key, T value){
    node<T>* temp = head;
    while(temp != nullptr){
        if(temp->data == key){
            node<T>* newnode = create_node(value);
            if(newnode == nullptr) return;
            if(temp->next == nullptr){
                temp->next = newnode;
                newnode->prev = temp;
                tail = newnode;
            }
            else{
                newnode->next = temp->next;
                newnode->prev = temp;
                temp->next->prev = newnode;
                temp->next = newnode;
            }
            n_size++;
            if(value == temp->data) temp = temp->next;
        }
        temp = temp->next;
    }
}

template <class T>
void doubly_list<T>::insert_before_key_value(T key, T value) {
    node<T>* temp = head;
    while(temp != nullptr){
        if(temp->data == key){
            node<T>* newnode = create_node(value);
            if(newnode == nullptr) return;
            if(temp->prev == nullptr){
                newnode->next = temp;
                temp->prev = newnode;
                head = newnode;
            }
            else{
                newnode->next = temp;
                newnode->prev = temp->prev;
                temp->prev->next = newnode;
                temp->prev = newnode;
            }
            n_size++;
        }
        temp = temp->next;
    } 
}

template <class T>
void doubly_list<T>::erase(T value) {
    node<T>* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            node<T>* delete_node = temp;
            if (temp == head) {
                head = head->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
                temp = temp->next;
            } else {
                temp->prev->next = temp->next;
                if (temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                    temp = temp->next;
                } else {
                    tail = tail->prev;
                    temp = temp->next;
                }
            }
            delete delete_node;
            n_size--;
        } else {
            temp = temp->next;
        }
    }
}

template <class T>
void doubly_list<T>::erase_at_location(int location){
    if(head == nullptr) return;
    if(location < 1 || location > n_size) return;
    if(location == 1){
         pop_front();
         return;
    }
    if(location == n_size){
         pop_back();
         return;
    }
    node<T>* temp = head;
    for(int i = 1; i <= location-1; i++) temp = temp->next;
    node<T>* delete_node = temp;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete delete_node;
    n_size--;
}

template <class T>
node<T>* doubly_list<T>::find(T value){
    node<T>* temp = head;
    while(temp != nullptr){
        if(temp->data == value) return temp;
        temp = temp->next;
    }
    return nullptr;
}

template <class T>
node<T>* Merge(node<T>* left, node<T>* right, bool (*cmp) (T, T)){
    if(left == nullptr && right == nullptr) return nullptr;
    if(left == nullptr){
        return right;
    }
    else if (right == nullptr){
        return left;
    }
    node<T>* result = nullptr;
    if(cmp(left->data, right->data)){
        result = left;
        result->next = Merge(left->next, right, cmp);
        if (result->next != nullptr) {
            result->next->prev = result;
        } 
    }
    else{
        result = right;
        result->next = Merge(left, right->next, cmp);
        if (result->next != nullptr) {
            result->next->prev = result;
        }
    }
    return result;
}

template <class T>
void Merge_Sort(node<T>* &head, bool (*cmp) (T, T)){
    if(head == nullptr || head->next == nullptr){
        return;
    }
    node<T>* left = head;
    node<T>* right = head->next;
    left->next = nullptr;
    right->prev = nullptr;
    Merge_Sort(left, cmp);
    Merge_Sort(right, cmp);
    head = Merge(left, right, cmp);
}

template <class T>
void doubly_list<T>::sort(bool (*cmp) (T, T)){
    Merge_Sort(head, cmp);
    while(tail->next != nullptr) tail = tail->next;
}

template <class T>
void doubly_list<T>::reverse(){
    if (head == nullptr || head->next == nullptr) return;
    node<T>* temp = head;
    while (temp != nullptr){
        swap(temp->next, temp->prev);
        temp = temp->prev;
    }
    swap(head, tail);
}









