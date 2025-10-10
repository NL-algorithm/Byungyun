#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
int n;
int board[503][503];
int cache[503][503];
pair<int,int> dir[] = {{1,0},{-1,0},{0,1},{0,-1}};

int DP(int r, int c) {
    int &ret = cache[r][c];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dir[i].first;
        int nc = c + dir[i].second;
        if (nr < 0 || nr >= n || nc < 0 || nc >= n)
            continue;
        if (board[nr][nc] <= board[r][c])
            continue;
        ret = max(ret, DP(nr, nc));
    }
    return ret += 1;
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
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, DP(i, j));
        }
    }
    cout << ans << '\n';
    return 0;
}
