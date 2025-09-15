#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

vector<int> adj[1'000'003];
vector<bool> visited;

void remove_link(int from, int target) {
    for (int i = 0; i < adj[from].size(); i++)
    {
        if(adj[from][i] == target) {
            adj[from].erase(adj[from].begin() + i);
            return ;
        }
    }
}

int n;
int main() {
    fio;
    cin >> n;
    visited.assign(n + 3, false);
    int u,v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> Q;
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() == 1) {
            visited[i] = true;
            Q.push(i);
        }
    }

    int ans = 0;

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for(int ad : adj[cur]) {
            if (visited[ad]) continue;
            ans++;
            visited[ad] = true;
            for(int adad : adj[ad]) {
                if (!visited[adad] && adj[adad].size() == 2) {
                    remove_link(adad, ad);
                    visited[adad] = true;
                    Q.push(adad);
                }
            }
        }
    }
    cout << ans;

    return 0;
}
