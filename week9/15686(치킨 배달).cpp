#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
using pr = pair<int, int>;
int n, m, h, ck;
pr houses[101];
pr chikens[14];
bool use[14];
int board[51][51];
int ans = 987654321;

int calc() {
    int ret = 0;
    for (int i = 0; i < h; i++) {
        int min_d = 987654321;
        for (int j = 0; j < ck; j++) {
            if (!use[j]) continue;
            int d = abs(chikens[j].first - houses[i].first) 
            + abs(chikens[j].second - houses[i].second);
            min_d = min(d, min_d);
        }
        ret += min_d;
    }
    return ret;
}

void back(int idx, int cnt) {
    if (idx == ck) {
        if (cnt == m)
            ans = min(ans, calc());
        return;
    }
    if (ck - idx < m - cnt)
        return;
    if (cnt < m) {
        use[idx] = true;
        back(idx + 1, cnt + 1);
        use[idx] = false;
    }
    back(idx + 1, cnt);
}

int main() {
    fio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                houses[h++] = {i, j};
            } else if (board[i][j] == 2) {
                chikens[ck++] = {i, j};
            }
        }
    }
    back(0, 0);
    cout << ans;
    return 0;
}
