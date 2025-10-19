#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
int n, m;

int words[10003];
int main() {
    fio;
    cin >> n >> m;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (char c : str) {
            words[i] |= 1 << (c - 'a');
        }
    }

    int t;
    char c;
    int num = (1 << 26) - 1;
    for (int i = 0; i < m; i++) {
        cin >> t >> c;
        if (t == 1) {
            num &= ~(1 << (c - 'a'));
        } else {
            num |= 1 << (c - 'a');
        }
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cnt += ((words[j] & num) == words[j]);
        }
        cout << cnt << '\n';
    }

    return 0;
}
