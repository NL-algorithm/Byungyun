#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n, q;
int psum[1'003];
int main() {
    fio;
    cin >> n >> q;
    int a, b = 0;
    cin >> a;
    psum[1] = 0;
    b = a;
    for (int i = 2; i <= n; i++) {
        cin >> a;
        psum[i] = abs(a - b) + psum[i - 1];
        b = a;
    }

    int l,r;
    while (q--) {
        cin >> l >> r;
        cout << psum[r] - psum[l] << '\n';
    }

    return 0;
}
