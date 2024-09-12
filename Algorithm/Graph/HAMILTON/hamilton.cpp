#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int MAXN = 10000;

int n, m;
set<int> adj[MAXN];
bool check[MAXN];
int halminton[MAXN];
int cnt = 1;
bool is_halminton = false;

void print_halminton() {
    for (int i = 1; i < cnt; i++)
        cout << halminton[i] << " ";
}

int start;
void Try(int u) {
    check[u] = true;
    halminton[cnt] = u;
    cnt++;
    if (cnt == n + 1) {
        if (adj[u].count(start) > 0) {
            is_halminton = true;
            print_halminton();
            cout << start << endl;
        }
    } else {
        for (int it : adj[u]) {
            if (!check[it]) {
                Try(it);
            }
        }
    }
    // Quay Lui
    cnt--;
    check[u] = false;
}

int main() {
    freopen("/Users/vuthevy1209/Documents/C++/input.rtf", "r", stdin);
    freopen("/Users/vuthevy1209/Documents/C++/output.rtf", "w", stdout);
    cin >> n >> m;
    if(n < 3){
        cout << "Khong ton tai chu trinh Halmilton trong do thi nay !";
        return 0;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    fill(check, check + n + 1, false);
    for (int i = 1; i <= n; i++) {
        start = i;
        if (!adj[i].empty()) {
            Try(i);
        }
    }
    if(is_halminton == false){
        cout << "Khong ton tai chu trinh Halmilton trong do thi nay !";
    }
    return 0;
}
