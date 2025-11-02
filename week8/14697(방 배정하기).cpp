#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

int main() {
    fio;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = 0; a * i <= d; i++) {
        for (int j = 0; b * j <= d; j++) {
            if (d < a * i + b * j) break;
            if ((d - (a * i + b * j)) % c == 0) {
                cout << '1';
                return 0;
            }
        }
    }
    cout << '0';

    return 0;
}
