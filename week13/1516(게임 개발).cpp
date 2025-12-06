#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
queue<pair<int, int>> Q;
vector<int> anj[501];
int parent[501];
int mtime[501];
int ans[501];
int main() {
    FastIO;
    cin >> n;
    int tower;
    for (int i = 1; i <= n; ++i) {
        cin >> mtime[i];
        while (true) {
            cin >> tower;
            if (tower == -1)
                break;
            anj[tower].push_back(i);
            parent[i]++;
        }
    }
    for (int i = 1; i <= n; ++i)
        if (parent[i] == 0)
            Q.emplace(i, 0);

    while (!Q.empty()) {
        auto [cur, t] = Q.front();
        Q.pop();
        ans[cur] = max(ans[cur], t + mtime[cur]);
        for (int x : anj[cur]) {
            parent[x]--;
            ans[x] = max(ans[x], ans[cur] + mtime[x]);
            if (parent[x] == 0)
                Q.emplace(x, ans[cur]);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}