#include <iostream>
#include <cmath>
using namespace std;

void bubble_sort(int a[], int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(a[j] > a[j+1]) swap(a[j], a[j+1]);
        }
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
    bubble_sort(a, n);
    for(int i = 0; i<n; i++){
        cout << a[i] << " ";
    }
    return 0;
}