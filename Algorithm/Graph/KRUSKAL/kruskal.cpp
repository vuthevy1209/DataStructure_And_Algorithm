#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <climits> 
#include <cstring> 
#include <cstdio>  
using namespace std;

struct edge{
    int _start_, _end_, _weight_;
};
int n, m;
int parent[10000];
int set_size[1000000];


void make_set(){
    for (int i = 1; i<=n; i++){
        parent[i] = i;
        set_size[i] = 1;
    }
}

int find(int u){
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}

bool Union(int u, int v){
    int parent_u = find(u);
    int parent_v = find(v);
    if (parent_u == parent_v) return false;
    if (set_size[parent_u] < set_size[parent_v]){
        parent[parent_u] = parent_v;
        set_size[parent_v] += set_size[parent_u];
    } else {
        parent[parent_v] = parent_u;
        set_size[parent_u] += set_size[parent_v];
    }
    return true;
}

vector<edge> E;
void input(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        E.push_back({x, y, w});
    }
}

bool cmp(edge x, edge y){
    return x._weight_ < y._weight_;
}

void kruskal(){
    vector<edge> MST;
    int Sum_weight_MST = 0;
    sort(E.begin(), E.end(), cmp);
    for (int i = 0; i < m; i++){
        if (MST.size() == n-1) break; // đã tạo xong cây khung
        edge e = E[i];
        if(Union(e._start_, e._end_)){
            MST.push_back(e);
            Sum_weight_MST = Sum_weight_MST + e._weight_;
        }
    }
    if (MST.size() != n-1){
        cout << "do thi khong lien thong" << endl;
    }
    else{
        cout << "Cay khung nho nhat: " << Sum_weight_MST << endl;
        for (edge it : MST){
            cout << it._start_ << "-" << it._end_ << " " << it._weight_ << endl;
        }
    }
}

int main(){
    freopen("/Users/vuthevy1209/Documents/C++/input.rtf", "r", stdin);
    freopen("/Users/vuthevy1209/Documents/C++/output.rtf", "w", stdout);
    input();
    make_set();
    kruskal();
}
