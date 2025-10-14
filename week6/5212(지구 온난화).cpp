#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
using pr = pair<int, int>;
int r, c;
string board[11];

int check(int vr, int vc) {
    int ret = 0;
    static pr dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (int i = 0; i < 4; i++) {
        int nr = vr + dir[i].first;
        int nc = vc + dir[i].second;
        if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
            ret++;
            continue;
        }
        ret += board[nr][nc] == '.';
    }
    return ret >= 3;
}

int main() {
    fio;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> board[i];
    }

    pr lt = {11, 11}, rb{0, 0};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == '.') continue;
            if (check(i, j)) {
                board[i][j] = '?';
            } else {
                lt.first = min(lt.first, i);
                lt.second = min(lt.second, j);
                rb.first = max(rb.first, i);
                rb.second = max(rb.second, j);
            }
        }
    }

    for (int i = lt.first; i <= rb.first; i++) {
        for (int j = lt.second; j <= rb.second; j++) {
            if (board[i][j] == 'X') cout << 'X';
            else cout << '.';
        }
        cout << '\n';
    }

    return 0;
}