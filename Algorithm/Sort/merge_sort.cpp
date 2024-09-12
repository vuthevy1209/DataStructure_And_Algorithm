#include <iostream>
#include <cmath>
using namespace std;

void merge(int a[], int l, int m, int r){
    int n1 = m - l + 1, n2 = r - m;
    int x[10000], y[10000];
    for(int i = 0; i<n1; i++) x[i] = a[l + i];
    for(int i = 0; i<n2; i++) y[i] = a[m + i + 1];
    int i = 0, j = 0, index = l;
    while(i < n1 && j < n2){
        if(x[i] <= y[j])
            a[index++] = x[i++];
        else
            a[index++] = y[j++];
    }
    while(i < n1) a[index++] = x[i++];
    while(j < n2) a[index++] = y[j++];
}


void merge_sort(int a[], int l, int r){
    if(l<r){
        int m = (l + r) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);
        merge(a, l, m, r);
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
    merge_sort(a, 0, n-1);
    for(int i = 0; i<n; i++){
        cout << a[i] << " ";
    }
    return 0;
}