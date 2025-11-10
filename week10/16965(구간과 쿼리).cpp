#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

pair<int, int> panels[104];
vector<int> adj[104];

bool check(int a, int b) {
    int x1 = panels[a].first;
    int y1 = panels[a].second;
    int x2 = panels[b].first;
    int y2 = panels[b].second;

    return (x2 < x1 && x1 < y2) || (x2 < y1 && y1 < y2);
}

vector<bool> visited;
bool dfs(int cur, int target) {
    if (cur == target) return true;
    visited[cur] = true;
    for (int nxt : adj[cur]) {
        if (!visited[nxt]) {
            bool res = dfs(nxt, target);
            if (res) return true;
        }
    }
    return false;
}

int n;
int main() {
    fio;
    cin >> n;
    int q, a, b;
    int idx = 0;
    for (int _ = 0; _ < n; _++) {
        cin >> q >> a >> b;
        if (q == 1) {
            panels[idx] = {a, b};
            for (int j = 0; j < idx; j++) {
                if (check(idx, j))
                    adj[idx].push_back(j);
                if (check(j, idx))
                    adj[j].push_back(idx);
            }
            idx++;
        } else {
            visited.assign(104, false);
            if (dfs(a - 1, b - 1)) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
    }

    return 0;
}
