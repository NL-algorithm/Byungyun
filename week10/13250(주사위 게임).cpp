#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

int n;
double cache[1'000'003];
double DP(int x) {
    if (x >= n)
        return 0;
    double &ret = cache[x];
    if (ret > -0.9)
        return ret;

    ret = 0;
    for (int i = 1; i <= 6; i++) {
        ret += (DP(x + i) + 1) / 6.0;
    }

    return ret;
}

int main() {
    fio;
    memset(cache, -1, sizeof(cache));
    cin >> n;
    cout.precision(13);
    cout << DP(0);

    return 0;
}
