#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e9 + 1;
vector<vector<pair<int, int>>> g, g2;
vector<int> order;
vector<bool> mark, mark2;
int n, cnt;

void dfs(int v, int gasV) {
    mark[v] = true;

    for (pair<int, int> i : g[v]) {
        if (!mark[i.first] && gasV >= i.second) {
            dfs(i.first, gasV);
        }
    }
    order.emplace_back(v);
}

void dfs2(int v, int gasV) {
    mark2[v] = true;

    for (pair<int, int> i : g2[v]) {
        if (!mark2[i.first] && gasV >= i.second) {
            dfs2(i.first, gasV);
        }
    }
    cnt++;
}
bool path_to_dfs(int gas) {
    mark.assign(n, false);
    mark2.assign(n, false);
    order.clear();
    for (int i = 0; i < n; i++) {
        if (!mark[i]) {
            dfs(i, gas);
        }
    }
    cnt = 0;
    if (order.size() > 0) {
        int help = order.back();
        dfs2(help, gas);
    }
    return cnt == n;
}
int main() {
    freopen("avia.in", "r", stdin);
    freopen("avia.out", "w", stdout);
    int z, left = -1, right = 1e9;
    cin >> n;


    g.resize(n);
    g2.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> z;
            if (i == j) {
                continue;
            }
            g[i].emplace_back(make_pair(j, z));
            g2[j].emplace_back(make_pair(i, z));
        }
    }

    while (left + 1 < right) {
        int m = (left + right) / 2;
        if (path_to_dfs(m)) {
            right = m;
        } else {
            left = m;
        }
    }

    cout << right << endl;


    return 0;
}