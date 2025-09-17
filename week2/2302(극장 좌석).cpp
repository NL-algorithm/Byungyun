#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int n, m;
bool isVIP[45];
int cache[45][2];

int DP(int idx, int traded) {
    if (idx == n) return 1;
    int& ret = cache[idx][traded];
    if (ret != -1) return ret;

    ret = DP(idx + 1, 0);
    if (traded != 1 && !isVIP[idx] && !isVIP[idx + 1]) {
        ret += DP(idx + 1, 1);
    }

    return ret;
}

int main() {
    fio;
    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    int x;
    for (int i = 0; i < m; i++) {
        cin >> x;
        isVIP[x] = true;
    }

    cout << DP(1, 0);

    return 0;
}
