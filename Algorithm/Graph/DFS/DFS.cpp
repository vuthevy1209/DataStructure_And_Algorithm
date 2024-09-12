#include <iostream>
#include <set>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
set<int> adjacent_list[10000];
bool visited[10000];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adjacent_list[x].insert(y);
        adjacent_list[y].insert(x);
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u) {
    cout << u << " ";
    visited[u] = true;
    for (auto v : adjacent_list[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}


int main() {
    
    input();
    DFS(1); // BFS(1)
    return 0;
}