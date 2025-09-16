#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
using pr = pair<int,int>;

#define INF 1'000'000'000

int R,C;
pr D, S;
vector<pr> Waters;
string board[51];
vector<vector<int>> dist(51, vector<int>(51, INF));
vector<vector<int>> water_dist(51, vector<int>(51, INF));
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void bfs(vector<pr> start, vector<vector<int>> &cdist, bool is_water) {
    queue<pr> Q;
    for (pr st : start) {
        Q.push(st);
        cdist[st.first][st.second] = 0;
    }
    while (!Q.empty())
    {
        auto [r, c] = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (board[nr][nc] == 'X') continue;
            if (is_water && board[nr][nc] == 'D') continue;

            if (cdist[nr][nc] == INF) {
                if (!is_water && water_dist[nr][nc] <= cdist[r][c] + 1) continue;
                cdist[nr][nc] = cdist[r][c] + 1;
                Q.emplace(nr, nc);
            }
        }
    }
}

int main() {
    fio;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> board[i];
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'D') 
                D = {i, j};
            else if (board[i][j] == 'S')
                S = {i, j};
            else if (board[i][j] == '*')
                Waters.emplace_back(i, j);
        }
    }

    bfs(Waters, water_dist, true);
    bfs({S}, dist, false);

    if (dist[D.first][D.second] == INF) cout << "KAKTUS";
    else cout << dist[D.first][D.second];

    return 0;
}
