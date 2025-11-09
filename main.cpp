#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
int n, m, d;
int origin_board[16][16];
int archers[4];
int ans = -1;
int top_enemy = -1;

#ifndef BOJ
void print_board(const vector<vector<int>>& target) {
    cout << "---------------------\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << target[i][j] << ' ';
        }
        cout << '\n';
    }
}
#endif

vector<vector<int>> make_copy_board() {
    vector<vector<int>> copy(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            copy[i][j] = origin_board[i][j];
        }
    }
    return copy;
}

void move_board(vector<vector<int>> &board) {
    for (int i = n - 1; i > 0; i--) {
        board[i] = move(board[i - 1]);
    }
    board[0].assign(m, 0);
}

int trial() {
    using pr = pair<int,int>;
    int ret = 0;
    static pr dir[3] = {{0, -1},{1, 0},{0, 1}};
    vector<vector<int>> dist(n, vector<int>(m, -1));

    return ret;
}

int simul() {
    int ret = 0;
    auto copy_board = make_copy_board();
    for (int i = 0; i < top_enemy; i++) {
        ret += trial();
        move_board(copy_board);
    }
    return ret;
}

void back(int idx) {
    if (idx == 4) {
        ans = max(ans, simul());
        return;
    }
    for (int i = archers[idx - 1] + 1; i < m - (3 - idx); i++) {
        archers[idx] = i;
        back(idx + 1);
    }
}

int main() {
    fio;
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> origin_board[i][j];
            if (origin_board[i][j] == 1 && top_enemy == -1)
                top_enemy = n - i;
        }
    }
    archers[0] = -1;
    back(1);
    cout << ans;
    return 0;
}

// 궁수 배치 경우의 수: 15 * 14 * 13 / 6 = 5 * 7 * 13 = 455
// 적 시뮬레이션 최대 횟수: 15
// 각 시뮬레이션당 연산 횟수: 대충 225
// 총합 150만정도