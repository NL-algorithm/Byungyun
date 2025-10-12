#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int main() {
    fio;
    int l,p,v;
    int t = 1;
    while (true) {
        cin >> l >> p >> v;
        if (l == 0) break;
        cout << "Case " << t << ": " << v / p * l + min(v % p, l) << '\n';
        t++;
    }

    return 0;
}
