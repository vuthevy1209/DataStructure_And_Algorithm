#include "Heap.h"

bool min_cmp(int a, int b){
    return a < b;
}

bool max_cmp(int a, int b){
    return a > b;
}

int main(){
    freopen("/Users/vuthevy1209/Documents/C++/input.rtf", "r", stdin);
    freopen("/Users/vuthevy1209/Documents/C++/output.rtf", "w", stdout);

    int n; cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    Heap<int> min_heap(arr, n, min_cmp);
    Heap<int> max_heap(arr, n, max_cmp);

    cout << "Min-heap: ";
    while(!min_heap.empty()){
        cout << min_heap.top() << " ";
        min_heap.pop();
    }
    cout << endl;

    cout << "Max-heap: ";
    while(!max_heap.empty()){
        cout << max_heap.top() << " ";
        max_heap.pop();
    }
    cout << endl;

    delete[] arr;
    return 0;
}
