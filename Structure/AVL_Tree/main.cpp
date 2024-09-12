#include "AVL.h"

void LNR(node<int>* root){
    if(root != nullptr){
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
}

void NLR(node<int>* root){
    if(root != nullptr){
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

void LRN(node<int>* root){
    if(root != nullptr){
        LRN(root->left);
        LRN(root->right);
        cout << root->data << " ";
    }
}


int main(){
    freopen("/Users/vuthevy1209/Documents/C++/input.rtf", "r", stdin);
    freopen("/Users/vuthevy1209/Documents/C++/output.rtf", "w", stdout);
    AVL<int> a;
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        int x; cin >> x;
        a.insert(x);
    }
    node<int>* it = a.get_root();
    cout << "Duyet NLR : "; NLR(it);
    cout << endl;
    cout << "Duyet LNR : "; LNR(it);
    cout << endl;
    cout << "Duyet LRN : "; LRN(it);
    cout << endl;
    cout << "-----------------------\n";


    a.insert(999);
    

    node<int>* it2 = a.get_root();
    cout << "Duyet NLR : "; NLR(it2);
    cout << endl;
    cout << "Duyet LNR : "; LNR(it2);
    cout << endl;
    cout << "Duyet LRN : "; LRN(it2);
    cout << endl;
    cout << endl;

}