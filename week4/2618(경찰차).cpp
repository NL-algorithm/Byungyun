#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
int n, w;
pair<int, int> incidents[1005];
int cache[1005][1005];
pair<int,int> his[1005][1005];

int dis(const pair<int, int> &a, const pair<int, int> &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int DP(int car1, int car2) {
    int last = max(car1, car2);
    if (last == w + 1)
        return 0;

    int &ret = cache[car1][car2];
    if (ret != -1)
        return ret;

    int car1_go = DP(last + 1, car2) + dis(incidents[last + 1], incidents[car1]);
    int car2_go = DP(car1, last + 1) + dis(incidents[last + 1], incidents[car2]);
    if (car1_go < car2_go) {
        ret = car1_go;
        his[car1][car2] = {last + 1, car2};
    } else {
        ret = car2_go;
        his[car1][car2] = {car1, last + 1};
    }

    return ret;
}

int main() {
    fio;
    memset(cache, -1, sizeof(cache));
    cin >> n >> w;
    incidents[0] = {1, 1};
    incidents[1] = {n, n};
    int r, c;
    for (int i = 2; i < w + 2; i++) {
        cin >> r >> c;
        incidents[i] = {r, c};
    }
    cout << DP(0, 1) << '\n';
    pair<int, int> cur = {0, 1};
    for (int i = 0; i < w; i++) {
        auto nxt = his[cur.first][cur.second];
        if (cur.first == nxt.first) {
            cout << 2 << '\n';
        }
        else {
            cout << 1 << '\n';
        }
        cur = nxt;
    }

    return 0;
}
