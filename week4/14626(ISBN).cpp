
#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
string str;
int arr[10] = {0, 7, 4, 1, 8, 5, 2, 9, 6, 3};
int main() {
    fio;
    cin >> str;
    int x = 0;
    bool m;
    for (int i = 0; i < 13; i++) {
        if (str[i] == '*') {
            m = i % 2 == 0;
            continue;
        }
        x += (str[i] - '0') * (i % 2 == 0 ? 1 : 3);
    }
    int ans = (10 - (x % 10)) % 10;
    if (m) cout << ans;
    else cout << arr[ans];

    return 0;
}

