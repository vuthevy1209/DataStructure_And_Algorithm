#include "PriorityQueue.h"

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
    vector<int> values(n), priorities(n);
    for(int i = 0; i < n; i++){
        cin >> values[i] >> priorities[i];
    }

    PriorityQueue<int, int> min_q(min_cmp);
    PriorityQueue<int, int> max_q(max_cmp);

    vector<int> handles(n);
    for(int i = 0; i < n; i++){
        handles[i] = min_q.push(values[i], priorities[i]);
        max_q.push(values[i], priorities[i]);
    }

    if(n > 0){
        min_q.update_key(handles[0], priorities[0] - 10);
    }

    cout << "Min-priority-queue: ";
    while(!min_q.empty()){
        cout << "(" << min_q.top() << "," << min_q.top_priority() << ") ";
        min_q.pop();
    }
    cout << endl;

    cout << "Max-priority-queue: ";
    while(!max_q.empty()){
        cout << "(" << max_q.top() << "," << max_q.top_priority() << ") ";
        max_q.pop();
    }
    cout << endl;

    return 0;
}
