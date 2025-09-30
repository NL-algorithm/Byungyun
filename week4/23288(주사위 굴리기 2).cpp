#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
int n, m, k;
int board[21][21];
int score_board[21][21];
pair<int, int> dice = {0, 0};
pair<int, int> dir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int dice_val[6] = {1, 2, 3, 4, 5, 6};
int dice_state[6] = {0, 1, 2, 3, 4, 5};

// 동쪽
void go_right() {
    int temp = dice_state[0];
    dice_state[0] = dice_state[3];
    dice_state[3] = dice_state[5];
    dice_state[5] = dice_state[2];
    dice_state[2] = temp;
}

// 서쪽
void go_left() {
    int temp = dice_state[0];
    dice_state[0] = dice_state[2];
    dice_state[2] = dice_state[5];
    dice_state[5] = dice_state[3];
    dice_state[3] = temp;
}

void go_up() {
    int temp = dice_state[0];
    dice_state[0] = dice_state[4];
    dice_state[4] = dice_state[5];
    dice_state[5] = dice_state[1];
    dice_state[1] = temp;
}

void go_down() {
    int temp = dice_state[0];
    dice_state[0] = dice_state[1];
    dice_state[1] = dice_state[5];
    dice_state[5] = dice_state[4];
    dice_state[4] = temp;
}

void move(int d) {
    switch (d) {
    case 0:
        go_right();
        break;
    case 1:
        go_down();
        break;
    case 2:
        go_left();
        break;
    case 3:
        go_up();
        break;
    }
}

int visited[21][21];

int dfs(int r, int c, int num, int idx) {
    int ret = 1;
    visited[r][c] = idx;
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i].first;
        int nc = c + dir[i].second;
        if (nr < 0 || nr >= n || nc < 0 || nc >= m)
            continue;
        if (visited[nr][nc] != 0 || board[nr][nc] != num)
            continue;
        ret += dfs(nr, nc, num, idx);
    }
    return ret;
}

void make_score_board() {
    int idx = 1;
    vector<int> score(401, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0) {
                int s = dfs(i, j, board[i][j], idx) * board[i][j];
                score[idx++] = s;
                score_board[i][j] = s;
            } else {
                score_board[i][j] = score[visited[i][j]];
            }
        }
    }
}

int main() {
    fio;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    make_score_board();

    int d = 0;
    int score = 0;
    for (int i = 0; i < k; i++) {
        int r = dice.first + dir[d].first;
        int c = dice.second + dir[d].second;
        if (r < 0 || r >= n || c < 0 || c >= m) {
            d = (d + 2) % 4;
            i--;
            continue;
        }
        score += score_board[r][c];
        dice = {r, c};
        move(d);

        int dice_bottom = dice_val[dice_state[5]];
        if (dice_bottom > board[r][c]) {
            d = (d + 1) % 4;
        } else if (dice_bottom < board[r][c]) {
            d = (d + 3) % 4;
        }
    }
    cout << score;

    return 0;
}
