#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <climits> 
#include <cstring> 
#include <cstdio>  
using namespace std;

int n;
int parent[10000];

//===========Phiên bản đơn giản=================//
void make_set(){
    for (int i = 1; i<=n; i++){
        parent[i] = i;
    }
}

int find(int u){
    if(u == parent[u]) 
        return u;
    return find(parent[u]);
}

void Union(int u, int v){
    int parent_u = find(u);
    int parent_v = find(v);
    if (parent_u != parent_v) return;
    parent[parent_u] = parent_v;
}
//===============================================//

//=================Phiên bản tối ưu==============//
int set_size[1000000];

void make_set_2(){
    for (int i = 1; i<=n; i++){
        parent[i] = i;
        set_size[i] = 1;
    }
}

int find_2(int u){
    if (u == parent[u])
        return u;
    return parent[u] = find_2(parent[u]);
}

void Union_2(int u, int v){
    int parent_u = find_2(u);
    int parent_v = find_2(v);
    if (parent_u == parent_v) return;
    if (set_size[parent_u] < set_size[parent_v]){
        parent[parent_u] = parent_v;
        set_size[parent_v] += set_size[parent_u];
    } else {
        parent[parent_v] = parent_u;
        set_size[parent_u] += set_size[parent_v];
    }
}


