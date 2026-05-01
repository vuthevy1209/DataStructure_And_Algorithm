template <class T>
bool Heap<T>::empty(){
    return data.empty();
}

template <class T>
int Heap<T>::size(){
    return static_cast<int>(data.size());
}

template <class T>
T Heap<T>::top(){
    if(empty()) return T();
    return data[0];
}

template <class T>
void Heap<T>::heapify_up(int idx){
    while(idx > 0){
        int parent = (idx - 1) / 2;
        if(cmp(data[idx], data[parent])){
            swap(data[idx], data[parent]);
            idx = parent;
        }else break;
    }
}

template <class T>
void Heap<T>::heapify_down(int idx){
    int n = size();
    while(true){
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int best = idx;

        if(left < n && cmp(data[left], data[best])) best = left;
        if(right < n && cmp(data[right], data[best])) best = right;

        if(best != idx){
            swap(data[idx], data[best]);
            idx = best;
        }else break;
    }
}

template <class T>
void Heap<T>::push(T value){
    data.push_back(value);
    heapify_up(size() - 1);
}

template <class T>
void Heap<T>::pop(){
    if(empty()) return;
    data[0] = data.back();
    data.pop_back();
    if(!empty()) heapify_down(0);
}

template <class T>
void Heap<T>::build(T* arr, int n){
    data.clear();
    for(int i = 0; i < n; i++) data.push_back(arr[i]);
    for(int i = n / 2 - 1; i >= 0; i--) heapify_down(i);
}
