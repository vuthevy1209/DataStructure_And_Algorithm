#include <iostream>
#include <cmath>
using namespace std;

int partition_LOMUTO(int a[], int l, int r){
    int i = l-1, pivot = a[r];
    for(int j = l; j<=r; j++){
        if(a[j] <= pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    return i;
}

void Quick_sort_with_LOMUTO(int a[], int l, int r){
    if(l < r){
        int pos = partition_LOMUTO(a, l, r);
        Quick_sort_with_LOMUTO(a, l, pos-1);
        Quick_sort_with_LOMUTO(a, pos + 1, r);
    }
}

int partition_HOARE(int a[], int l, int r){
    int pivot = a[l];
    int i = l - 1;
    int j = r + 1;
    while(true){
        do{
            i++;
        } while(a[i] < pivot);
        do{
            j--;
        } while(a[j] > pivot);

        if(i < j) swap(a[i], a[j]);
        else return j;
    }
}


void Quick_sort_with_HOARE(int a[], int l, int r){
    if(l < r){
        int pos = partition_HOARE(a, l, r);
        Quick_sort_with_HOARE(a, l, pos);
        Quick_sort_with_HOARE(a, pos + 1, r);
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
    Quick_sort_with_HOARE(a, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}