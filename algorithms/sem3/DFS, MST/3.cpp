#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
 
using namespace std;
vector<vector<int>> g;
vector<int> tin, fup;
set<int> ans;
vector<bool> mark;
 
void dfs(int v, int p = -1) {
    mark[v] = true;
    tin[v] = fup[v] = (p == -1 ? 0 : tin[p] + 1);
    int cnt = 0;
    for (int i : g[v]) {
        int to = i;
        if (to == p) {
            continue;
        }
        if (mark[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] >= tin[v] && p != -1) {
                ans.insert(v);
            }
            cnt += 1;
        }
    }
    if (p == -1 && cnt > 1) {
        ans.insert(v);
    }
 
}
 
int main() {
    int n, m, x, y;
    cin >> n >> m;
    g.resize(n + 1);
 
 
    mark.resize(n + 1, false);
    tin.resize(n + 1);
    fup.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x - 1].emplace_back(y - 1);
        g[y - 1].emplace_back(x - 1);
    }
 
    for (int i = 0; i < n; ++i) {
        if (mark[i] == 0) {
            dfs(i);
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans) {
        cout << i + 1 << " ";
    }
    cout << endl;
 
    return 0;
}