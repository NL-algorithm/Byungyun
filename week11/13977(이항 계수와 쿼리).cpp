#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
using ll = long long;

constexpr ll M = 1'000'000'007;

int m, n, k;
ll fact[4000001];

void pre() {
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= 4000000; ++i) {
        fact[i] = (fact[i - 1] * i) % M;
    }
}

ll power(const ll num, ll depth) {
    if (depth == 1)
        return num;
    if (depth % 2 == 0) {
        ll temp = power(num, depth / 2);
        return (temp * temp) % M;
    } else {
        ll temp = power(num, (depth - 1) / 2);
        return ((num * temp) % M * temp) % M;
    }
}

ll ncr(int n, int k) {
    ll ans = 1;
    ans = fact[n];
    ll r = (fact[k] * fact[n - k]) % M;
    return (ans * power(r, M - 2)) % M;
}

int main() {
    fio;
    pre();
    cin >> m;
    while (m--) {
        cin >> n >> k;
        cout << ncr(n, k) << '\n';
    }

    return 0;
}