#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

inline int tri(int x) {
    return x * x * x;
}

int main() {
    fio;
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            for (int c = b; c <= 100; c++) {
                for (int d = c; d <= 100; d++) {
                    if (tri(a) == tri(b) + tri(c) + tri(d)) {
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\n";
                    }
                }
            }
        }
    }

    return 0;
}
