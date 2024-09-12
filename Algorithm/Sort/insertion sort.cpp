#include <iostream>
#include <cmath>
using namespace std;

void insertion_sort(int a[], int n){
    for(int i = 1; i<n; i++){
        int location_insert = i-1;
        int value_insert = a[i];
        while(location_insert >= 0 && value_insert < a[location_insert]){
            a[location_insert + 1] = a[location_insert];
            location_insert--;
        }
        a[location_insert + 1] = value_insert;
    }
}


int main(){
    //freopen("/Users/vuthevy1209/Documents/C++/input.rtf", "r", stdin);
    //freopen("/Users/vuthevy1209/Documents/C++/output.rtf", "w", stdout);
    int n; cin >> n;
    int a[10000];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    insertion_sort(a, n);
    for(int i = 0; i<n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
