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

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        cout << x << " ";
        for(auto it : adjacent_list[x]){
            if(!visited[it]){
                visited[it] = true;
                q.push(it);
            }
        }
    }

}


int main() {
    
    input();
    BFS(1); // DFS(1)
    return 0;
}