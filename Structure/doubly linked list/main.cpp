#include "DoublyList.h"


bool cmp(char x, char y){
    return x < y;
}
int main(){
    freopen("/Users/vuthevy1209/Documents/C++/input.rtf", "r", stdin);
    freopen("/Users/vuthevy1209/Documents/C++/output.rtf", "w", stdout);
    //while(true){}
    doubly_list<char> a;
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        char x; cin >> x;
        a.push_back(x);
    }
    if(a.empty()){
        cout << "Danh sach rong !" << endl;
    }
    else{
        cout << "Duyet xuoi : ";
        node<char>* temp = a.begin();
            while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
        }
        cout << endl;
        cout << "Duyet nguoc : ";
        node<char>* temp1 = a.end();
        while(temp1 != nullptr){
            cout << temp1->data << " ";
            temp1 = temp1->prev;
        }
        cout << endl;
    }
    cout << "Size list : " << a.size() << endl;
    if(!a.empty()) cout << "Begin : " << a.begin()->data << endl;
    else cout << "Begin : " << "nullptr" << endl;
    if(!a.empty()) cout << "Back : " << a.end()->data << endl;
    else cout << "Back : " << "nullptr" << endl;
    cout << "---------------------------------\n";

    
    a.sort(cmp);


    if(a.empty()){
        cout << "Danh sach rong !" << endl;
    }
    else{
        cout << "Duyet xuoi : ";
        node<char>* temp = a.begin();
            while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
        }
        cout << endl;
        cout << "Duyet nguoc : ";
        node<char>* temp1 = a.end();
        while(temp1 != nullptr){
            cout << temp1->data << " ";
            temp1 = temp1->prev;
        }
        cout << endl;
    }
    cout << "Size list : " << a.size() << endl;
    if(!a.empty()) cout << "Begin : " << a.begin()->data << endl;
    else cout << "Begin : " << "nullptr" << endl;
    if(!a.empty()) cout << "Back : " << a.end()->data << endl;
    else cout << "Back : " << "nullptr" << endl;
    return 0;
}