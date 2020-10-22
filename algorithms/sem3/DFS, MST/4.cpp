#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<pair<int, int>>> g;
vector<int> tin, fup, ans;
vector<bool> mark;
vector<int> colors;
int time = 0, mc = 0;

void paint (int v, int color) {
    colors[v] = color;
    for (pair<int, int> i : g[v]) {
        if (!colors[i.first]) {
            if (fup[i.first] > tin[v]) {
                mc++;
                paint(i.first, mc);
            } else {
                paint(i.first, color);
            }
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
    colors.resize(n);
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

    for (int i = 0; i < n; ++i) {
        if (colors[i] == 0) {
            mc++;
            paint(i, mc);
        }
    }

    cout << mc << endl;

    for (int i : colors) {
        cout << i << ' ';
    }

    return 0;
}