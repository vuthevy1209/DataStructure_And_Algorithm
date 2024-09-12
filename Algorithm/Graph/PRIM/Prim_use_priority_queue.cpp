#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <climits> // Include this header for INT_MAX
#include <cstring> // Include this header for memset
#include <algorithm>
#include <numeric>
using namespace std;

struct edge{
    int _start_, _end_, _weight_;
};

int n, m;
bool visited[100000]; // visited[i] = True : i thuộc V(MST),  visited[i] = False : i thuộc V  
vector<pair<int, int>> adjacent_list[100000]; // first là đỉnh, second là cạnh
int d[10000];
int parent[10000];


void _input_(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++ ){
        int x, y, w; cin >> x >> y >> w;
        adjacent_list[x].push_back({y, w});
        adjacent_list[y].push_back({x, w});
    }
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++) d[i] = INT_MAX;
}

void Prim(int u){
    //hàng đợi ưu tiên lưu cặp {du, u} với du là trọng số của cạnh nối với u
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    //Khởi tạo cây khung MST
    int Sum_weight_MST = 0; 
    vector<edge> MST;
    q.push({0, u});

    while (!q.empty()){
        int vertices = q.top().second;
        int weight = q.top().first;
        q.pop();
        // Nếu đỉnh đang xét đã thuộc tập V(MST) rồi thì bỏ qua
        if (visited[vertices] == true) continue;

        Sum_weight_MST = Sum_weight_MST + weight;
        if (u != vertices){
            MST.push_back({vertices, parent[vertices], weight});
        }
        visited[vertices] = true;

        for(auto it : adjacent_list[vertices]){
            int v = it.first, w = it.second;
            if (!visited[v] && w < d[v]){
                q.push({w, v});
                d[v] = w;
                parent[v] = vertices; 
            } 
        }
    }
    cout << Sum_weight_MST << endl;
    for (auto it : MST){
        cout << it._start_ << "-" << it._end_ << " " << it._weight_ << endl;
    }
}

int main(){
    freopen("/Users/vuthevy1209/Documents/C++/input.rtf", "r", stdin);
    freopen("/Users/vuthevy1209/Documents/C++/output.rtf", "w", stdout);
    _input_();
    Prim(1);
}