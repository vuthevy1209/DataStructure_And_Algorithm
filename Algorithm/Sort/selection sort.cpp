#include <iostream>
#include <cmath>
using namespace std;

void selection_sort(int a[], int n){
    for(int i = 0; i<n-1; i++){
        int Min = i;
        for(int j = i+1; j<n; j++){
            if(a[j] < a[Min]) Min = j;
        }
        swap(a[i], a[Min]);
    }
}


int main(){
    freopen("/Users/vuthevy1209/Documents/C++/input.rtf", "r", stdin);
    freopen("/Users/vuthevy1209/Documents/C++/output.rtf", "w", stdout);
    int n; cin >> n;
    int a[10000];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    selection_sort(a, n);
    for(int i = 0; i<n; i++){
        cout << a[i] << " ";
    }
    return 0;
}