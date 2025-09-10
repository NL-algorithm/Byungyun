#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
using i64 = long long;
constexpr i64 mod = 1'000'000'000;

int n;
i64 cache[103][11][1030];

i64 DP(int idx, int num, int bit) {
    if (idx == n - 1) {
        if (bit == (1 << 10) - 1)
            return 1;
        return 0;
    }
    auto &ret = cache[idx][num][bit];
    if (ret != -1)
        return ret;

    ret = 0;
    if (num < 9) {
        ret = (ret % mod + DP(idx + 1, num + 1, bit | (1 << (num + 1))) % mod) % mod;
    }
    if (num > 0) {
        ret = (ret % mod + DP(idx + 1, num - 1, bit | (1 << (num - 1))) % mod) % mod;
    }

    return ret;
}

int main() {
    fio;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    i64 ret = 0;
    for (int i = 1; i < 10; i++) {
        ret = (ret % mod + DP(0, i, 1 << i) % mod) % mod;
    }
    cout << ret;

    return 0;
}
