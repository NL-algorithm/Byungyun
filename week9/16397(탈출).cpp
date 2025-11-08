#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int n, t, g;
array<int, 100005> dist;

int calc(int x) {
    x *= 2;
    if (x >= 100000)
        return x;
    string temp = to_string(x);
    if (temp[0] != '0')
        temp[0]--;
    return stoi(temp);
}

int main() {
    fio;
    fill(dist.begin(), dist.end(), -1);
    cin >> n >> t >> g;
    queue<int> Q;
    Q.push(n);
    dist[n] = 0;

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        if (cur == g) {
            cout << dist[cur] << '\n';
            return 0;
        }

        if (dist[cur] >= t)
            continue;
        
        int nx1 = calc(cur);
        int nx2 = cur + 1;
        if (nx1 < 100000 && dist[nx1] == -1) {
            dist[nx1] = dist[cur] + 1;
            Q.push(nx1);
        }
        if (nx2 < 100000 && dist[nx2] == -1) {
            dist[nx2] = dist[cur] + 1;
            Q.push(nx2);
        }
    }

    cout << "ANG";
    return 0;
}
