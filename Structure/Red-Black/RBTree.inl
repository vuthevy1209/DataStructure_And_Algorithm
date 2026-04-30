template <class T>
node<T>* RBTree<T>::create_node(T value){
    node<T>* temp = new node<T>;
    temp->data = value;
    temp->color = RED;
    temp->left = NIL;
    temp->right = NIL;
    temp->parent = NIL;
    return temp;
}

template <class T>
node<T>* RBTree<T>::SEARCH(node<T>* virtual_root, T value){
    while(virtual_root != NIL){
        if(value == virtual_root->data) return virtual_root;
        if(value < virtual_root->data) virtual_root = virtual_root->left;
        else virtual_root = virtual_root->right;
    }
    return NIL;
}

template <class T>
node<T>* RBTree<T>::minimum(node<T>* virtual_root){
    while(virtual_root->left != NIL) virtual_root = virtual_root->left;
    return virtual_root;
}

template <class T>
void RBTree<T>::left_rotate(node<T>* x){
    node<T>* y = x->right;
    x->right = y->left;
    if(y->left != NIL) y->left->parent = x;
    y->parent = x->parent;
    if(x->parent == NIL) root = y;
    else if(x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

template <class T>
void RBTree<T>::right_rotate(node<T>* x){
    node<T>* y = x->left;
    x->left = y->right;
    if(y->right != NIL) y->right->parent = x;
    y->parent = x->parent;
    if(x->parent == NIL) root = y;
    else if(x == x->parent->right) x->parent->right = y;
    else x->parent->left = y;
    y->right = x;
    x->parent = y;
}

template <class T>
void RBTree<T>::insert(T value){
    node<T>* z = create_node(value);
    node<T>* y = NIL;
    node<T>* x = root;

    while(x != NIL){
        y = x;
        if(z->data < x->data) x = x->left;
        else if(z->data > x->data) x = x->right;
        else {
            delete z;
            return;
        }
    }

    z->parent = y;
    if(y == NIL) root = z;
    else if(z->data < y->data) y->left = z;
    else y->right = z;

    insert_fixup(z);
}

template <class T>
void RBTree<T>::insert_fixup(node<T>* z){
    while(z->parent->color == RED){
        if(z->parent == z->parent->parent->left){
            node<T>* y = z->parent->parent->right;
            if(y->color == RED){
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }else{
                if(z == z->parent->right){
                    z = z->parent;
                    left_rotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                right_rotate(z->parent->parent);
            }
        }else{
            node<T>* y = z->parent->parent->left;
            if(y->color == RED){
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }else{
                if(z == z->parent->left){
                    z = z->parent;
                    right_rotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                left_rotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

template <class T>
void RBTree<T>::transplant(node<T>* u, node<T>* v){
    if(u->parent == NIL) root = v;
    else if(u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;
    v->parent = u->parent;
}

template <class T>
void RBTree<T>::erase(T value){
    node<T>* z = SEARCH(root, value);
    if(z == NIL) return;

    node<T>* y = z;
    node<T>* x;
    Color y_original = y->color;

    if(z->left == NIL){
        x = z->right;
        transplant(z, z->right);
    }else if(z->right == NIL){
        x = z->left;
        transplant(z, z->left);
    }else{
        y = minimum(z->right);
        y_original = y->color;
        x = y->right;
        if(y->parent == z){
            x->parent = y;
        }else{
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    delete z;
    if(y_original == BLACK) delete_fixup(x);
}

template <class T>
void RBTree<T>::delete_fixup(node<T>* x){
    while(x != root && x->color == BLACK){
        if(x == x->parent->left){
            node<T>* w = x->parent->right;
            if(w->color == RED){
                w->color = BLACK;
                x->parent->color = RED;
                left_rotate(x->parent);
                w = x->parent->right;
            }
            if(w->left->color == BLACK && w->right->color == BLACK){
                w->color = RED;
                x = x->parent;
            }else{
                if(w->right->color == BLACK){
                    w->left->color = BLACK;
                    w->color = RED;
                    right_rotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                left_rotate(x->parent);
                x = root;
            }
        }else{
            node<T>* w = x->parent->left;
            if(w->color == RED){
                w->color = BLACK;
                x->parent->color = RED;
                right_rotate(x->parent);
                w = x->parent->left;
            }
            if(w->right->color == BLACK && w->left->color == BLACK){
                w->color = RED;
                x = x->parent;
            }else{
                if(w->left->color == BLACK){
                    w->right->color = BLACK;
                    w->color = RED;
                    left_rotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                right_rotate(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}
