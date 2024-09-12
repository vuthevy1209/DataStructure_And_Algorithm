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

void _input_(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++ ){
        int x, y, w; cin >> x >> y >> w;
        adjacent_list[x].push_back({y, w});
        adjacent_list[y].push_back({x, w});
    }
    memset(visited, false, sizeof(visited));
}

void Prim(int u){
    //Khởi tạo cây khung rỗng
    int Sum_weight_MST = 0; 
    vector<edge> MST;

    visited[u] = true; // cho đinh u vào MST
    while (MST.size() < n - 1){
        // Tìm cạnh có trọng số nhỏ nhất sao cho 1 đỉnh thuộc V(MST) và một đỉnh thuộc V
        int _start_min, _end_min;
        int _weight_min = INT_MAX;
        for (int i = 1; i <= n; i++){
            if (visited[i] == true){
                for (auto it : adjacent_list[i]){
                    int v = it.first, weight = it.second;
                    if (visited[v] == false && weight < _weight_min){
                        _start_min = i;
                        _end_min = v;
                        _weight_min = weight;
                    }
                }
            }
        }
        // thêm cạnh vừa tìm được vào MST
        MST.push_back({_start_min, _end_min, _weight_min});
        Sum_weight_MST = Sum_weight_MST + _weight_min;
        // cho đỉnh vừa được chọn vào tập V(MST), đồng thời cũng loại bỏ ra khỏi tập V
        visited[_end_min] = true; 
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
    Prim(4);
}




