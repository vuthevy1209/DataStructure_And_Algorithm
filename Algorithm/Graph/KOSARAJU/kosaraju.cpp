#include <iostream>
#include <set>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

int n, m;
vector<int> adjacent_list[10000];
vector<int> adjacent_list_reverse[100000];
bool visited[10000];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adjacent_list[x].push_back(y);
        adjacent_list_reverse[y].push_back(x); 
    }
    memset(visited, false, sizeof(visited));
}

stack<int> topo;
void TOPO_SORT(int u){
    visited[u] = true;
    for (auto v : adjacent_list[u]){
        if (!visited[v]){
            TOPO_SORT(v);
        }
    }
    topo.push(u);
}

void DFS(int u) { 
    cout << u << " ";
    visited[u] = true;
    for (auto v : adjacent_list_reverse[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int sothanhphanlienthongmanh = 0;
void kosaraju(int u){
    TOPO_SORT(u);
    memset(visited, false, sizeof(visited));
    while (!topo.empty()){
        int top = topo.top(); topo.pop();
        if(!visited[top]){
            sothanhphanlienthongmanh++;
            DFS(top);
            cout << endl;
        }
    }
    cout << sothanhphanlienthongmanh;
}

int main(){
    freopen("/Users/vuthevy1209/Documents/C++/input.rtf", "r", stdin);
    freopen("/Users/vuthevy1209/Documents/C++/output.rtf", "w", stdout);
    input();
    kosaraju(1);
}
