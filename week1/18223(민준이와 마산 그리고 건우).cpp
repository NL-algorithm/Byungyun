#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
using pr = pair<int,int>;

vector<pr> adj[5'003];
vector<int> dist;

int n, m, p;

void pathfind(int st) {
    priority_queue<pr, vector<pr>, greater<>> pq;
    dist[st] = 0;
    pq.emplace(0, st);
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
}

int main() {
    fio;
    cin >> n >> m >> p;
    int u,v,c;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        adj[u].emplace_back(c,v);
        adj[v].emplace_back(c,u);
    }
    dist.assign(n + 2, 1'000'000'000);
    pathfind(1);
    int to_goal = dist[n];
    int to_p = dist[p];
    dist.assign(n + 2, 1'000'000'000);
    pathfind(p);
    int from_p_to_goal = dist[n];

    if (to_p + from_p_to_goal == to_goal) {
        cout << "SAVE HIM";
    }
    else {
        cout << "GOOD BYE";
    }

    return 0;
}
