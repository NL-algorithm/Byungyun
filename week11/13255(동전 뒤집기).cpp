#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

int n, k;
int arr[51];
double cache[51][1003], cache2[1003][1003];

double comb(int n, int r) {
    if (n == r || r == 0)
        return 1;
    if (cache2[n][r] == 0)
        cache2[n][r] = comb(n - 1, r) + comb(n - 1, r - 1);
    return cache2[n][r];
}

double DP(int idx, int front) {
    if (idx == k) {
        return front;
    }
    double &ret = cache[idx][front];
    if (ret > -0.5)
        return ret;
    ret = 0;
    int st = max(0, arr[idx] - n + front);
    int ed = min(arr[idx], front);
    for (int i = st; i <= ed; i++) {
        ret += DP(idx + 1, front - i + (arr[idx] - i)) * comb(front, i) * comb(n - front, arr[idx] - i) / comb(n, arr[idx]);
    }
    return ret;
}

int main() {
    fio;
    memset(cache, -1, sizeof(cache));
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    cout << fixed;
    cout.precision(13);
    cout << DP(0, n);
    return 0;
}
