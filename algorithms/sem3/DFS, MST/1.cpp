#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
vector<vector<int>> g;
vector<int> mark;
vector<int> ans;
 
void dfs(int v) {
    mark[v] = 1;
    for (int i : g[v]) {
        if (mark[i] == 1) {
            cout << -1 << endl;
            exit(0);
        }
        if (mark[i] == 0) {
            dfs(i);
        }
    }
    mark[v] = 2;
    ans.emplace_back(v);
}
 
int main() {
    int n, m, x, y;
    cin >> n >> m;
    g.resize(n + 1);
 
 
    for (int i = 0; i <= n; i++) {
        mark.emplace_back(0);
    }
 
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x - 1].emplace_back(y - 1);
    }
 
    for (int i = 0; i < n; ++i) {
        if (mark[i] == 0) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans) {
        cout << i + 1 << ' ';
    }
    cout << endl;
 
    return 0;
}