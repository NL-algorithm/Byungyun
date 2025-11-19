#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int d1, d2;
int main() {
    fio;
    unordered_set<int> ans;
    ans.insert(1);
    cin >> d1 >> d2;
    for (int i = d1; i <= d2; i++) {
        pair<int,int> v = {2, i};
        for (int j = 1; j < i; j++) {
            int x = gcd(v.first * j, v.second);
            ans.insert((v.first * j / x * 10000) + (v.second / x));
        }
    }
    cout << ans.size();

    return 0;
}
