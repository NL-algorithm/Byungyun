#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
int T, n, m;
int main() {
    fio;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((i * i + j * j + m) % (i * j) == 0) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
