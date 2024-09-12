#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <climits> // Include this header for INT_MAX
#include <cstring> // Include this header for memset
#include <cstdio>  // Include this header for freopen
using namespace std;

int n, m;
int _start_, _end_;
vector<pair<int, int>> adjacent_list[10000];
vector<int> Min_distance(100000); // distance_from_source_to_u
int parent[10000];

void _input_(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        adjacent_list[x].push_back({y, w});
        //adjacent_list[y].push_back({x, w});
    }
    cin >> _start_ >> _end_;
}

void Dijkstra(int vertices){
    fill(Min_distance.begin(), Min_distance.end(), 999999);
    Min_distance[vertices] = 0;
    //hàng đợi lưu cặp {dx, x} với dx là khoảng cách ngắn nhất từ nguồn tới x
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, vertices}); 
    while (!q.empty()){
        int u = q.top().second;
        int du = q.top().first;
        q.pop();
        if (du > Min_distance[u]) continue;

        for(auto it : adjacent_list[u]){
            int v = it.first;
            int uv = it.second;
            if (Min_distance[v] > Min_distance[u] + uv){
                Min_distance[v] = Min_distance[u] + uv;
                parent[v] = u;
                q.push({Min_distance[v], v});
            }
        }
    }   
}

void print_shortest_distance_from_start_to_end(){
    for (int i = 1; i <= n; i++){
        cout << i << " " << parent[i] << endl;
    }
    stack<int> s;
    while (parent[_end_] != _start_){
        s.push(_end_);
        _end_ = parent[_end_];
    }
    s.push(_end_); s.push(parent[_end_]);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    
}


int main(){
    freopen("/Users/vuthevy1209/Documents/C++/input.rtf", "r", stdin);
    freopen("/Users/vuthevy1209/Documents/C++/output.rtf", "w", stdout);
    _input_();
    Dijkstra(1);
    print_shortest_distance_from_start_to_end();
    return 0;
}
