#include <iostream>
using namespace std;

// Điều kiện áp dụng: mảng đã được sắp xếp
bool binary_search(int a[], int n, int value){
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(value < a[mid])
            right = mid - 1;
        else if (value > a[mid])
            left = mid + 1;
        else return true;
    }
    return false;
}
int main(){
    int a[1000];
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    if(binary_search(a, n, 2)) cout << "YES";
    else cout << "NO";
    return 0;

}
