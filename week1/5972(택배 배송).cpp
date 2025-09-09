#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
using pr = pair<int,int>;

vector<pr> adj[50'003];
int n,m;

int pathfind() {
    vector<int> dist(n + 2, 1'000'000'000);
    priority_queue<pr, vector<pr>, greater<>> pq;
    dist[1] = 0;
    pq.emplace(0, 1);
    while (!pq.empty())
    {
        auto [c, idx] = pq.top();
        pq.pop();
        if (c != dist[idx]) continue;
        for (auto [ncost, nidx] : adj[idx]) {
            if (dist[nidx] > dist[idx] + ncost) {
                dist[nidx] = dist[idx] + ncost;
                pq.emplace(dist[nidx], nidx);
            }
        }
    }
    return dist[n];
}

int main() {
    fio;
    cin >> n >> m;
    int u,v,c;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        adj[u].emplace_back(c,v);
        adj[v].emplace_back(c,u);
    }
    cout << pathfind();

    return 0;
}
