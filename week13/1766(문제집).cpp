#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m;
vector<int> tree[32005];
int parent[32005];
priority_queue<int, vector<int>, greater<>> Q;

int main() {
    FastIO;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        tree[a].push_back(b);
        parent[b]++;
    }
    for (int i = 1; i <= n; ++i)
        if (parent[i] == 0)
            Q.push(i);
    int cur;
    while (!Q.empty()) {
        cur = Q.top();
        Q.pop();
        cout << cur << ' ';
        for (int x : tree[cur]) {
            parent[x]--;
            if (parent[x] == 0)
                Q.push(x);
        }
    }

    return 0;
}