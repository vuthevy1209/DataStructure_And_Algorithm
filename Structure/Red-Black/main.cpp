#include "RBTree.h"

void LNR(node<int>* root, node<int>* nil){
    if(root != nil){
        LNR(root->left, nil);
        cout << root->data << " ";
        LNR(root->right, nil);
    }
}

void NLR(node<int>* root, node<int>* nil){
    if(root != nil){
        cout << root->data << " ";
        NLR(root->left, nil);
        NLR(root->right, nil);
    }
}

void LRN(node<int>* root, node<int>* nil){
    if(root != nil){
        LRN(root->left, nil);
        LRN(root->right, nil);
        cout << root->data << " ";
    }
}

int main(){
    freopen("/Users/vuthevy1209/Documents/C++/input.rtf", "r", stdin);
    freopen("/Users/vuthevy1209/Documents/C++/output.rtf", "w", stdout);

    RBTree<int> a;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.insert(x);
    }

    node<int>* it = a.get_root();
    node<int>* nil = a.get_nil();
    cout << "Duyet NLR : "; NLR(it, nil);
    cout << endl;
    cout << "Duyet LNR : "; LNR(it, nil);
    cout << endl;
    cout << "Duyet LRN : "; LRN(it, nil);
    cout << endl;
    cout << "-----------------------\n";

    a.insert(999);
    a.erase(999);

    node<int>* it2 = a.search(999);
    if(it2) cout << "Value : " << it2->data;
    else cout << "nullptr";
    cout << endl;

    return 0;
}
