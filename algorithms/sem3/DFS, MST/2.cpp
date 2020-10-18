#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
vector<vector<pair<int, int >>> g;
vector<int> tin, fup, ans;
vector<bool> mark;
int time = 0;
 
void dfs(int v, int p = -1) {
    mark[v] = true;
    tin[v] = fup[v] = time++;
    for (pair<int, int> i : g[v]) {
        int to = i.first;
        if (to == p) {
            continue;
        }
        if (mark[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                ans.emplace_back(i.second);
            }
        }
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
        g[x - 1].emplace_back(y - 1, i + 1);
        g[y - 1].emplace_back(x - 1, i + 1);
    }
 
    for (int i = 0; i < n; ++i) {
        if (mark[i] == 0) {
            dfs(i);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i : ans) {
        cout << i << endl;
    }
    cout << endl;
 
    return 0;
}