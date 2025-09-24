#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
int n, m, k;
int board[21][21];
pair<int, int> dice;

int dice_val[6] = {0, 0, 0, 0, 0, 0};

//                  top           bottom
int dice_state[6] = {0, 1, 2, 3, 4, 5};

/*
  1
3 0 2
  4
  5
*/

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
    case 1:
        go_right();
        break;
    case 2:
        go_left();
        break;
    case 3:
        go_up();
        break;
    case 4:
        go_down();
        break;
    }
}

pair<int, int> dir[] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int main() {
    fio;
    cin >> n >> m >> dice.first >> dice.second >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int d;
    for (int i = 0; i < k; i++) {
        cin >> d;
        int r = dice.first + dir[d - 1].first;
        int c = dice.second + dir[d - 1].second;
        if (r < 0 || r >= n || c < 0 || c >= m)
            continue;
        dice = {r, c};
        move(d);
        if (board[dice.first][dice.second] == 0) {
            // 주사위의 바닥면을 보드에 복사
            board[dice.first][dice.second] = dice_val[dice_state[5]];
        } else {
            // 보드의 값을 주사위의 바닥면에 복사
            dice_val[dice_state[5]] = board[dice.first][dice.second];
            board[dice.first][dice.second] = 0;
        }
        // 주사위의 맨 윗면을 출력
        cout << dice_val[dice_state[0]] << '\n';

        // for (int i = 0; i < 6; i++)
        // {
        //     cout << dice_state[i] << ' ';
        // }
        // cout << '\n';
        
    }

    return 0;
}
