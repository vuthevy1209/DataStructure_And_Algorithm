template <class T>
bool AVL<T>::empty(){
    return root == nullptr;
}

template <class T>
int AVL<T>::height(node<T> *t){
    if (t == nullptr)
        return -1;
    else
        return t->height;
}

template <class T>
void AVL<T>::Left_Left(node<T>* &k){
    node<T>* k1 = k->left;
    k->left = k1->right;
    k1->right = k;
    k->height = max(height(k->left), height(k->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k = k1;
}

template <class T>
void AVL<T>::Right_Right(node<T> *&k){
    node<T>* k1 = k->right;
    k->right = k1->left;
    k1->left = k;
    k->height = max(height(k->left), height(k->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k = k1;
}

template <class T>
void AVL<T>::Left_Right(node<T> *&k){
    Right_Right(k->left);
    Left_Left(k);
}

template <class T>
void AVL<T>::Right_Left(node<T> *&k){
    Left_Left(k->right);
    Right_Right(k);
}

template <class T>
void AVL<T>::balance(node<T> *&k){
    if (k == nullptr)
        return;
    if (height(k->left) - height(k->right) > 1){
        if (height(k->left->left) >= height(k->left->right))
            Left_Left(k);
        else
            Left_Right(k);
    }
    else if (height(k->right) - height(k->left) > 1){
        if (height(k->right->right) >= height(k->right->left))
            Right_Right(k);
        else
            Right_Left(k);
    }
    k->height = max(height(k->left), height(k->right)) + 1;
}

template <class T>
node<T>* AVL<T>::create_node(T value){
    node<T>* newnode = new (nothrow) node<T>;
    if(newnode == nullptr){return nullptr;}
    newnode->data = value;
    newnode->left = nullptr;
    newnode->right = nullptr;
    newnode->height = 0;
    return newnode;
}

template <class T>
void AVL<T>::INSERT(node<T>* &virtual_root, T value){
    if(virtual_root == nullptr){
        node<T>* newnode = create_node(value);
        if(newnode == nullptr) return;
        virtual_root = newnode;
    }
    if(value == virtual_root->data) return;
    else if(value < virtual_root->data) INSERT(virtual_root->left, value);
    else INSERT(virtual_root->right, value);
    balance(virtual_root);
}

template <class T>
void AVL<T>::insert(T value){
    INSERT(root, value);
}

template <class T>
void AVL<T>::ERASE(node<T>* &virtual_root, T value){
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
    balance(virtual_root);
}

template <class T>
void AVL<T>::erase(T value){
    ERASE(root, value);
}

template <class T>
node<T>* AVL<T>::SEARCH(node<T>* virtual_root, T value){
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
node<T>* AVL<T>::search(T value){
    return SEARCH(root, value);   
}

template <class T>
node<T>* AVL<T>::get_root(){
    return root;
}