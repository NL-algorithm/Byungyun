#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
int n, m, k;
int Jsum[1'003][1'003];
int Osum[1'003][1'003];
int Isum[1'003][1'003];
int main() {
    fio;
    cin >> n >> m >> k;

    char s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s;
            Osum[i][j] = Osum[i][j - 1] - Osum[i - 1][j - 1] + Osum[i - 1][j];
            Jsum[i][j] = Jsum[i][j - 1] - Jsum[i - 1][j - 1] + Jsum[i - 1][j];
            Isum[i][j] = Isum[i][j - 1] - Isum[i - 1][j - 1] + Isum[i - 1][j];
            if (s == 'J') {
                Jsum[i][j]++;
            } else if (s == 'O') {
                Osum[i][j]++;
            } else {
                Isum[i][j]++;
            }
        }
    }

    int a, b, c, d;
    while (k--) {
        cin >> a >> b >> c >> d;
        cout << Jsum[c][d] - Jsum[a - 1][d] - Jsum[c][b - 1] + Jsum[a - 1][b - 1] << ' ';
        cout << Osum[c][d] - Osum[a - 1][d] - Osum[c][b - 1] + Osum[a - 1][b - 1] << ' ';
        cout << Isum[c][d] - Isum[a - 1][d] - Isum[c][b - 1] + Isum[a - 1][b - 1] << '\n';
    }

    return 0;
}
