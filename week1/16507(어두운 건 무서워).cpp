#include <bits/stdc++.h>

using namespace std;

inline void fio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int board[1003][1003];
int r, c, q;
int main() {
    fio();
    cin >> r >> c >> q;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> board[i][j];
            board[i][j] += board[i][j - 1] - board[i - 1][j - 1] + board[i - 1][j];
        }
    }
    int r1, r2, c1, c2, val, m;
    for (int i = 0; i < q; i++)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        val = board[r2][c2] - board[r2][c1 - 1] + board[r1 - 1][c1 - 1] - board[r1 - 1][c2];
        m = (r2 - r1 + 1) * (c2 - c1 + 1);
        cout << val / m << '\n';
    }
    
    return 0;
}
