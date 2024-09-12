#include "List.h"

bool cmp(int x, int y){
    return x > y;
}
int main(){

    freopen("/Users/vuthevy1209/Documents/C++/input.rtf", "r", stdin);
    freopen("/Users/vuthevy1209/Documents/C++/output.rtf", "w", stdout);
    //while(true){}
    list<int> a;
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    node<int>* temp = a.begin();
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    a.reverse();
    node<int>* temp3 = a.begin();
    while(temp3 != nullptr){
        cout << temp3->data << " ";
        temp3 = temp3->next;
    }
    cout << endl;
    cout << endl;
    cout << "Begin: " << a.begin()->data << endl;
    cout << "Back: " << a.end()->data << endl;
    cout << a.size() << endl;
    a.pop_back();


    node<int>* temp1 = a.begin();
    while(temp1 != nullptr){
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }
    cout << endl;
    if(a.begin() != nullptr) cout << "Begin: " << a.begin()->data << endl;
    if(a.end() != nullptr) cout  << "Back: " << a.end()->data << endl;
    cout << a.size() << endl;

    node<int>* it = a.find(2);
    if(it != nullptr) cout << it->data << endl;
    else cout << "nullptr" << endl;
    return 0;
}