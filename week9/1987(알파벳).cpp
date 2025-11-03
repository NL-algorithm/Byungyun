#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

int R, C;
string board[21];
pair<int,int> dir[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int visited[21][21];
int main() {
    fio;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> board[i];
    }
    int val = 1 << (board[0][0] - 'A');
    queue<tuple<int, int, unsigned>> Q;
    Q.emplace(0, 0, val);
    visited[0][0] = val;
    int ans = 0;
    while (!Q.empty()) {
        auto [r, c, v] = Q.front();
        ans = max(ans, popcount(v));
        Q.pop();
        for (auto[vr, vc] : dir) {
            int nr = r + vr;
            int nc = c + vc;
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            int nval = 1 << (board[nr][nc] - 'A');
            if ((v & nval) == 0 && visited[nr][nr] != nval)
                Q.emplace(nr, nc, v | nval);
        }
    }
    cout << ans;
    return 0;
}
