#include <iostream>
#include <cmath>
using namespace std;

void heapify(int a[], int n, int i){
    int largest = i;
    int left = largest * 2 + 1;
    int right = largest * 2 + 2;
    if(a[left] > a[largest] && left < n)
        largest = left;
    if(a[right] > a[largest] && right < n)
        largest = right;
    
    if (largest != i){
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heap_sort(int a[], int n){
    for(int i = n / 2 - 1; i>=0; i--){
        heapify(a, n, i);
    }
    for(int i = n-1; i>=0; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
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
    heap_sort(a, n);
    for(int i = 0; i<n; i++){
        cout << a[i] << " ";
    }
    return 0;
}