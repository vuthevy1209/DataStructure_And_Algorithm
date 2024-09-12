#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <climits> 
#include <cstring> 
#include <cstdio>  
using namespace std;

int n, m;
set<int> adjacent_list[10000];
bool edge[10000][10000]; //edge[x][y] = True: cạnh vẫn còn trong đồ thị, edge[x][y] = False: cạnh đã xóa
int deg[10000];

void input(){
    cin >> n >> m;
    for (int i = 0; i<m; i++){
        int x, y; cin >> x >> y;
        adjacent_list[x].insert(y);
        adjacent_list[y].insert(x);
        deg[x]++;
        deg[y]++;
    }
}

void euler(int vertices){
    vector<int> Euler_cycle;
    stack<int> s;
    s.push(vertices);
    while(!s.empty()){
        int u = s.top();
        if (adjacent_list[u].size() == 0){
            Euler_cycle.push_back(u);
            s.pop();
        } else {
            // lấy 1 đỉnh trong danh sách kề của u và push và stack đồng thời xóa cạnh u-v này đi
            int v = *adjacent_list[u].begin(); 
            s.push(v);
            adjacent_list[u].erase(v);
            adjacent_list[v].erase(u);
        }
    }

    // trả về kết quả
    if(Euler_cycle.front() != Euler_cycle.back()){
        cout << "KHONG CO CHU TRINH EULER" << endl;
        cout << "Duong di Euler la: ";
        for (int it : Euler_cycle){
            cout << it << " ";
        }
    } else {
        cout << "Chu trinh Euler la: ";
        for (int it : Euler_cycle){
            cout << it << " ";
        }
    }
}

void result(){
    int count = 0;
    for(int i = 1; i<=n; i++){
        if(deg[i] % 2 == 1) count++;
    }
    if(count > 2){
        cout << "Khong co chu trinh euler va khong co duong di euler";
    } else {
        euler(1);
    }
}
int main(){
    freopen("/Users/vuthevy1209/Documents/C++/input.rtf", "r", stdin);
    freopen("/Users/vuthevy1209/Documents/C++/output.rtf", "w", stdout);
    input();
    result();
}