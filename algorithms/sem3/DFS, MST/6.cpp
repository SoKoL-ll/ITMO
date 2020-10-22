#include <iostream>
#include <vector>
#include <set>

using namespace std;
vector<set<int>> g, g2;
vector<int> order, comp, vertex;
vector<bool> mark;
set<pair<int, int>> ans;

void dfs1(int v) {
    mark[v] = true;
    for (int i : g[v]) {
        if (!mark[i]) {
            dfs1(i);
        }
    }
    order.emplace_back(v);
}

void dfs2(int v) {
    mark[v] = true;
    comp.emplace_back(v);
    for (int i : g2[v]) {
        if (!mark[i]) {
            dfs2(i);
        }
    }
    order.emplace_back(v);
}

int main() {
    int n, m, x, y, cnt = 0;
    cin >> n >> m;
    g.resize(n + 1);
    g2.resize(n + 1);
    vertex.resize(n + 1);

    mark.resize(n + 1, false);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (x != y) {
            g[x - 1].insert(y - 1);
            g2[y - 1].insert(x - 1);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!mark[i]) {
            dfs1(i);
        }
    }
    mark.assign(n + 1, false);
    for (int i = 0; i < n; i++) {
        x = order[n - 1 - i];
        if (!mark[x]) {
            dfs2(x);
            cnt++;
            for (int j : comp) {
                vertex[j] = cnt;
            }
            comp.clear();
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j : g[i]) {
            if (vertex[i] != vertex[j]) {
                ans.insert(make_pair(vertex[i], vertex[j]));
            }
        }
    }

    cout << ans.size() << endl;
    return 0;
}