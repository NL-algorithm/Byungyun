#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#define INF 1'000'000'000

using namespace std;

int n, m, k;
int cache[101][301][301];
pair<int, int> arr[301];

int DP(int idx, int burger, int fries) {
    if (idx == n) {
        return 0;
    }
    int &ret = cache[idx][burger][fries];
    if (ret != -1)
        return ret;

    ret = DP(idx + 1, burger, fries);
    if (arr[idx].first <= burger && arr[idx].second <= fries) {
        ret = max(ret, DP(idx + 1, burger - arr[idx].first, fries - arr[idx].second) + 1);
    }
    
    return ret;
}

int main() {
    fio;
    memset(cache, -1, sizeof(cache));
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    cout << DP(0, m, k) << '\n';

    return 0;
}
