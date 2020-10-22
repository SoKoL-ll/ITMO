#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
const double INF = 1e9;
vector<bool> mark;
vector<float> mn;
vector<int> sel;
vector<pair<int, int>> enter;
int main() {
    int n, x, y;
    double ans = 0;

    cin >> n;

    mark.resize(n);
    mn.assign(n, INF);
    sel.assign(n, -1);
    mn[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        enter.emplace_back(make_pair(x, y));
    }

    for (int i = 0; i < n; i++) {
        x = -1;
        for (int j = 0; j < n; j++) {
            if (!mark[j] && (x == -1 || mn[j] < mn[x])) {
                x = j;
            }
        }
        mark[x] = true;
        if (sel[x] != -1) {
            ans += mn[x];
            //cout << x << " " << sel[x] << " " << mn[x] << endl;
        }
        for (int j = 0; j < n; j++) {
            auto help = (float)sqrt((enter[j].first - enter[x].first) * (enter[j].first - enter[x].first) +
                                    (enter[j].second - enter[x].second) * (enter[j].second - enter[x].second));
            if (help < mn[j]) {
                mn[j] = help;
                sel[j] = x;
            }
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}