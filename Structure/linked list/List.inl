template <class T>
int list<T>::size(){
    return n_size;
}

template <class T>
node<T>* list<T>::begin(){
    if (head == nullptr) return nullptr;
    else return head;
}

template <class T>
node<T>* list<T>::end(){
    if (head == nullptr) return nullptr;
    else{
        node<T>* tail = head;
        while(tail->next != nullptr) tail = tail->next;
        return tail;
    }
}

template <class T>
bool list<T>::empty(){
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
void list<T>::push_front(T value){
    node<T>* newnode = create_node(value);
    if(newnode == nullptr) return;
    if(head == nullptr) head = newnode;
    else{
        newnode->next = head;
        head = newnode;
    }
    n_size++;
}

template <class T>
void list<T>::push_back(T value){
    node<T>* newnode = create_node(value);
    if(newnode == nullptr) return;
    if(head == nullptr) head = newnode;
    else{
        node<T>* temp = head;
        while(temp->next != nullptr) temp = temp->next;
        temp->next = newnode;
    }
    n_size++;
}

template <class T>
void list<T>::pop_front(){
    if(head == nullptr) return;
    node<T>* temp = head;
    head = head->next;
    delete temp;
    n_size--;
}

template <class T>
void list<T>::pop_back(){
    if(head == nullptr) return;
    if(head->next == nullptr){
         pop_front();
         return;
    }
    node<T>* temp = head;
    while(temp->next->next != nullptr) temp = temp->next;
    node<T>* delete_node = temp->next;
    temp->next = nullptr;
    delete delete_node;
    n_size--;
}

template <class T>
void list<T>::insert_at_location(int location, T value){
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
    temp->next = newnode;
    n_size++;
}

template <class T>
void list<T>::insert_after_key_value(T key, T value){
    node<T>* temp = head;
    while(temp != nullptr){
        if(temp->data == key){
            node<T>* newnode = create_node(value);
            if(newnode == nullptr) return;
            newnode->next = temp->next;
            temp->next = newnode;
            n_size++;
            if(value == temp->data) temp = temp->next;
        }
        temp = temp->next;
    }
}

template <class T>
void list<T>::insert_before_key_value(T key, T value) {
    node<T>* temp = head;
    node<T>* prev = nullptr;
    while (temp != nullptr) {
        if (temp->data == key) {
            node<T>* newnode = create_node(value);
            if (newnode == nullptr) return;
            if (prev == nullptr) {
                newnode->next = head;
                head = newnode;
            } else {
                newnode->next = temp;
                prev->next = newnode;
            }
            n_size++;
        }
        prev = temp;
        temp = temp->next;
    }
}

template <class T>
void list<T>::erase(T value){
    if(head == nullptr) return;
    node<T>* temp = head;
    node<T>* prev = nullptr;
    while(temp != nullptr){
        if(temp->data == value){
            if(prev == nullptr){
                head = head->next;
            }
            else{
                prev->next = temp->next;
            }
            node<T>* delete_node = temp;
            temp = temp->next;
            delete delete_node;
            n_size--;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
}

template <class T>
void list<T>::erase_at_location(int location){
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
    for(int i = 1; i <= location-2; i++) temp = temp->next;
    node<T>* delete_node = temp->next;
    temp->next = temp->next->next;
    delete delete_node;
    n_size--;
}

template <class T>
node<T>* list<T>::find(T value){
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
    node<T>* result = nullptr;
    if(left == nullptr){
        return right;
    }
    else if (right == nullptr){
        return left;
    }
    if(cmp(left->data, right->data)){
        result = left;
        result->next = Merge(left->next, right, cmp);
    }
    else{
        result = right;
        result->next = Merge(left, right->next, cmp);
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
    Merge_Sort(left, cmp);
    Merge_Sort(right, cmp);
    head = Merge(left, right, cmp);
}

template <class T>
void list<T>::sort(bool (*cmp) (T, T)){
    Merge_Sort(head, cmp);
}

template <class T>
void REVERSE(node<T>* &head){
    if(head == nullptr || head->next == nullptr) return;
    node<T>* last = head;
    node<T>* temp = head->next;
    REVERSE(temp);
    last->next->next = last;
    last->next = nullptr;
    head = temp;
}
template <class T>
void list<T>::reverse(){
    REVERSE(head);
}








