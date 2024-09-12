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
    }
    memset(visited, false, sizeof(visited));
}

vector<int> topo;
void DFS(int u) {
    visited[u] = true;
    for (auto v : adjacent_list[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
    topo.push_back(u);
}
// sau khi xong thì lật ngược lại


int main() {
    freopen("/Users/vuthevy1209/Documents/C++/input.rtf", "r", stdin);
    freopen("/Users/vuthevy1209/Documents/C++/output.rtf", "w", stdout);
    input();
    for (int i = 1; i <= n; i++){
        if(!visited[i]){
            DFS(i);
        }
    }
    reverse(topo.begin(), topo.end());
    for (auto it : topo){
        cout << it << " ";
    }
    return 0;
}