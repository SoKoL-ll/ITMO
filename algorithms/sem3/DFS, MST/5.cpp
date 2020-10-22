#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<pair<int, int>>> g;
vector<int> tin, fup, colors;
vector<bool> mark, visit;
int mc = 0, time = 0;

void paint(int v, int color, int p) {
    visit[v] = true;
    for (pair<int, int> i : g[v]) {
        if (i.second == p) {
            continue;
        }
        if (!visit[i.first]) {
            if (fup[i.first] >= tin[v]) {
                int newcolor = ++mc;
                colors[i.second] = newcolor;
                paint(i.first, newcolor, i.second);
            } else {
                colors[i.second] = color;
                paint(i.first, color, i.second);
            }
        } else if (tin[i.first] < tin[v]) {
            colors[i.second] = color;
        }
    }
}
void dfs(int v, int p = -1) {
    mark[v] = true;
    tin[v] = fup[v] = time++;
    for (pair<int, int> i : g[v]) {
        if (i.second == p) {
            continue;
        }
        if (mark[i.first]) {
            fup[v] = min(fup[v], tin[i.first]);
        } else {
            dfs(i.first, i.second);
            fup[v] = min(fup[v], fup[i.first]);
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
    visit.resize(n + 1);
    colors.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x - 1].emplace_back(y - 1, i);
        g[y - 1].emplace_back(x - 1, i);
    }

    for (int i = 0; i < n; ++i) {
        if (mark[i] == 0) {
            dfs(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (visit[i] == 0) {
            paint(i, mc, -1);
        }
    }

    cout << mc << endl;
    for (int i = 0; i < m; i++) {
        cout << colors[i] << ' ';
    }

    return 0;
}