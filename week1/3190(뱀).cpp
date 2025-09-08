#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

const int apple = 1;
const int body = 2;

int n, k, l;
int board[103][103];
pair<int,char> ch_dir[103];
pair<int,int> dir[4] = {{0, 1}, {1,0}, {0,-1}, {-1, 0}};

#ifndef BOJ
void print_board() {
    cout << "[board]\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "\n\n";
}
#endif

int move_snake() {
    queue<pair<int,int>> Q;
    int cur_time = 1, d = 0, dir_idx = 0;

    Q.emplace(1, 1);
    board[1][1] = body;

    while (true) {
        auto head = Q.back();
        int nr = head.first + dir[d].first;
        int nc = head.second + dir[d].second;
        if (nr <= 0 || nr > n || nc <= 0 || nc > n || board[nr][nc] == body) {
            return cur_time;
        }
        if (board[nr][nc] != apple) {
            board[Q.front().first][Q.front().second] = 0;
            Q.pop();
        }
        Q.emplace(nr, nc);
        board[nr][nc] = body;
        if (cur_time == ch_dir[dir_idx].first) {
            if (ch_dir[dir_idx].second == 'D') {
                d = (d + 1) % 4;
            }
            else {
                d = (d - 1 < 0) ? 3 : d - 1;
            }
            dir_idx++;
        }
        cur_time++;
    }
}

int main() {
    fio;
    cin >> n >> k;
    int r, c;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        board[r][c] = apple;
    }
    cin >> l;
    for (int i = 0; i < l; ++i) {
        cin >> ch_dir[i].first >> ch_dir[i].second;
    }
    cout << move_snake();

    return 0;
}
