#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

vector<int> adj[1'000'003];
vector<bool> visited;
vector<bool> adapter;

int n;
int main() {
    //fio;
    cin >> n;
    visited.assign(n + 3, false);
    adapter.assign(n + 3, false);
    int u,v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(u);
        adj[v].push_back(v);
    }

    queue<int> Q;
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() == 1) {
            Q.push(i);
        }
    }

    int ans = 0;

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        cout << cur << '\n';

        if (visited[cur]) continue;
        visited[cur] = true;

        for(int ad : adj[cur]) {
            if (visited[ad]) continue;
            ans++;
            visited[ad] = true;
            for(int adad : adj[ad]) {
                if (!visited[adad]) {
                    Q.push(adad);
                }
            }
        }
    }
    cout << ans;
    

    return 0;
}
