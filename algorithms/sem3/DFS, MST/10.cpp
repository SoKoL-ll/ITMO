#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
const long long INF = 1e11;
vector<pair<int, pair<int, int>>> g;
vector<int> p;
vector<pair<int, int>> res;

int dsu_get (int v) {
    return (v == p[v]) ? v : (p[v] = dsu_get(p[v]));
}

void dsu_unite (int a, int b) {
    a = dsu_get(a);
    b = dsu_get(b);
    if (rand() & 1) {
        swap(a, b);
    }
    if (a != b) {
        p[a] = b;
    }
}


int main() {
    int n, m, x, y, z, cnt = 0;
    long long ans = 0;
    cin >> n >> m;

    p.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        g.emplace_back(make_pair(z, make_pair(x - 1, y - 1)));
       // g.emplace_back(make_pair(z, make_pair(y - 1, x - 1)));
    }

    sort(g.begin(), g.end());

    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a = g[i].second.first;
        int b = g[i].second.second;
        int govno = g[i].first;
        if (dsu_get(a) != dsu_get(b)) {
            cnt += govno;
            //res.emplace_back(g[i].second);
            ans += g[i].first;
            dsu_unite(a, b);
        }
    }

//    for (pair<int, int> i : res) {
//        cout << i.first + 1  << ' ' << i.second + 1 << endl;
//    }

    cout << ans << endl;
    return 0;
}
