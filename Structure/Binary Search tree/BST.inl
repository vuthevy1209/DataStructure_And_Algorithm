template <class T>
bool BST<T>::empty(){
    return root == nullptr;
}

template <class T>
node<T>* BST<T>::create_node(T value){
    node<T>* newnode = new (nothrow) node<T>;
    if(newnode == nullptr){return nullptr;}
    newnode->data = value;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

template <class T>
void BST<T>::INSERT(node<T>* &virtual_root, T value){
    if(virtual_root == nullptr){
        node<T>* newnode = create_node(value);
        if(newnode == nullptr) return;
        virtual_root = newnode;
    }
    if(value == virtual_root->data) return;
    else if(value < virtual_root->data) INSERT(virtual_root->left, value);
    else INSERT(virtual_root->right, value);
}

template <class T>
void BST<T>::insert(T value){
    INSERT(root, value);
}

template <class T>
void BST<T>::ERASE(node<T>* &virtual_root, T value){
    if(virtual_root == nullptr) return;
    if(value < virtual_root->data) ERASE(virtual_root->left, value);
    else if(value > virtual_root->data) ERASE(virtual_root->right, value);
    else{
        if(virtual_root->left == nullptr && virtual_root->right == nullptr){
            delete virtual_root;
            virtual_root = nullptr;
        }
        else if(virtual_root->right == nullptr){
            node<T>* delete_node = virtual_root;
            virtual_root = virtual_root->left;
            delete delete_node;
            delete_node = nullptr;
        }
        else if(virtual_root->left == nullptr){
            node<T>* delete_node = virtual_root;
            virtual_root = virtual_root->right;
            delete delete_node;
            delete_node = nullptr;
        }
        else{
            node<T>* temp = virtual_root->right;
            while(temp->left != nullptr) temp = temp->left;
            virtual_root->data = temp->data;
            ERASE(virtual_root->right, temp->data);
        }
    }
}

template <class T>
void BST<T>::erase(T value){
    ERASE(root, value);
}

template <class T>
node<T>* BST<T>::SEARCH(node<T>* virtual_root, T value){
    if(virtual_root == nullptr || virtual_root->data == value){
        return virtual_root;
    }
    else if(value < virtual_root->data){
        return SEARCH(virtual_root->left, value);
    }
    else {
        return SEARCH(virtual_root->right, value);
    }
}

template <class T>
node<T>* BST<T>::search(T value){
    return SEARCH(root, value);   
}

template <class T>
node<T>* BST<T>::get_root(){
    return root;
}