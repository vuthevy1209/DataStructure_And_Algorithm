#include <iostream>
#include <set>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
set<int> adjacent_list[10000];
bool visited[10000];
int deg_in[100000];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adjacent_list[x].insert(y);
        deg_in[y]++;

    }
    memset(visited, false, sizeof(visited));
}

vector<int> topo;
void kahn(){
    queue<int> q;
    for(int i = 1; i<=n; i++){
        if(deg_in[i] == 0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (auto it : adjacent_list[u]){
            deg_in[it]--;
            if(deg_in[it] == 0){
                q.push(it);
            }
        }
    }
}

int main(){
    freopen("/Users/vuthevy1209/Documents/C++/input.rtf", "r", stdin);
    freopen("/Users/vuthevy1209/Documents/C++/output.rtf", "w", stdout);
    input();
    kahn();
    for (auto it : topo){
        cout << it << " ";
    }
}