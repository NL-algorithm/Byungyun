#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

int n;
int board[33][33];
int cache[33][33][3];
pair<int, int> dir[3] = {{0, 1}, {1, 1}, {1, 0}};

int DP(int r, int c, int d) {
    if (r == n - 1 && c == n - 1) {
        return 1;
    }
    int &ret = cache[r][c][d];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = 0; i < 3; i++) {
        if (abs(d - i) == 2)
            continue;
        int nr = dir[i].first + r;
        int nc = dir[i].second + c;
        if (nr >= n || nc >= n) continue;
        if (board[nr][nc] == 1) continue;
        if (i == 1 && (board[r + 1][c] == 1 || board[r][c + 1] == 1))
            continue;

        ret += DP(nr, nc, i);
    }
    return ret;
}

int main() {
    fio;
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    cout << DP(0, 1, 0);

    return 0;
}
