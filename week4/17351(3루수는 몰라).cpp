#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
int n;
char board[502][502];
int cache[502][502][5];
string str = "MOLA";

int DP(int r, int c, int idx) {
    if (r >= n || c >= n) {
        if (idx == 4) return 1;
        return 0;
    }
    int &ret = cache[r][c][idx];
    if (ret != -1)
        return ret;

    if (board[r][c] == str[idx]) {
        idx++;
    } else if (board[r][c] == 'M') {
        idx = 1;
    } else {
        idx = 0;
    }

    if (idx == 4) {
        ret = 1;
        idx = 0;
    } else {
        ret = 0;
    }

    ret += max(DP(r + 1, c, idx), DP(r, c + 1, idx));

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
    cout << DP(0, 0, 0);

    return 0;
}
