#include <iostream>
using namespace std;


bool linear_search(int a[], int n, int value){
    for(int i = 0; i<n; i++){
        if(a[i] == value){
            return true;
        }
    }
    return false;
}
int main(){
    int a[1000];
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    if(linear_search(a, n, 2)) cout << "YES";
    else cout << "NO";
    return 0;

}
