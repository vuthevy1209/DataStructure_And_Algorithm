#include "BST.h"

void LNR(node<char>* root){
    if(root != nullptr){
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
}

void NLR(node<char>* root){
    if(root != nullptr){
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

void LRN(node<char>* root){
    if(root != nullptr){
        LRN(root->left);
        LRN(root->right);
        cout << root->data << " ";
    }
}


int main(){
    freopen("/Users/vuthevy1209/Documents/C++/input.rtf", "r", stdin);
    freopen("/Users/vuthevy1209/Documents/C++/output.rtf", "w", stdout);
    BST<char> a;
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        char x; cin >> x;
        a.insert(x);
    }
    node<char>* it = a.get_root();
    cout << "Duyet NLR : "; NLR(it);
    cout << endl;
    cout << "Duyet LNR : "; LNR(it);
    cout << endl;
    cout << "Duyet LRN : "; LRN(it);
    cout << endl;
    cout << "-----------------------\n";


    node<char>* it2 = a.search('c');
    if(it2) cout << "Value : " << it2->data;
    else cout << "nullptr";

    // node<int>* it2 = a.get_root();
    // cout << "Duyet NLR : "; NLR(it2);
    // cout << endl;
    // cout << "Duyet LNR : "; LNR(it2);
    // cout << endl;
    // cout << "Duyet LRN : "; LRN(it2);
    // cout << endl;
    // cout << endl;

}