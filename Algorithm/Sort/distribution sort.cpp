#include <iostream>
#include <cmath>
using namespace std;

int cnt[100000];
void  distribution_sort(int a[], int n){
    for(int i = 0; i<n; i++){
        cnt[a[i]]++;
    }
    int index = 0;
    for(int i = 0; i<100000; i++){
        for(int j = 0; j<cnt[i]; j++){
            a[index++] = i;
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
    distribution_sort(a, n);
    for(int i = 0; i<n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
