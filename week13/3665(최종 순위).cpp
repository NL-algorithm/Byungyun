#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

int T, n, m;
int convert[501];
int arr[501];
bool adj[501][501];
int parent[501];
int ans[501];

void print();
void tsort();

int main() {
    fio;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(adj, 0, sizeof(adj));
        memset(parent, 0, sizeof(parent));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                adj[i][j] = true;
                parent[j]++;
            }
        }

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            convert[arr[i] - 1] = i;
        }
        cin >> m;
        int u, v;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            u = convert[u - 1];
            v = convert[v - 1];
            if (u > v)
                swap(u, v);
            adj[u][v] = false;
            adj[v][u] = true;
            parent[u]++;
            parent[v]--;
        }
#ifndef BOJ
        print();
#endif
        tsort();
    }
    return 0;
}

void tsort() {
    fill(ans, ans + n, 0);
    queue<int> Q;
    int cur, idx = 0;
    for (int i = 0; i < n; ++i)
        if (parent[i] == 0)
            Q.push(i);
    while (!Q.empty()) {
        cur = Q.front();
        Q.pop();
        ans[idx++] = arr[cur];
        for (int i = 0; i < n; i++) {
            if (!adj[cur][i])
                continue;
            if (--parent[i] == 0)
                Q.push(i);
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ans[i];
    }
    if (sum != n * (n + 1) / 2) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

#ifndef BOJ
void print() {
    cout << "------------------------------------\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << parent[i] << ' ';
    }
    cout << '\n';
}
#endif
