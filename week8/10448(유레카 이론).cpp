#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
int T, k;

constexpr array<int, 46> make() {
    array<int, 46> tris{};
    for (int i = 1; i < 46; i++) {
        tris[i] = (i * (i + 1)) / 2;
    }
    return tris;
}

constexpr array<int, 46> tris = make();

int main() {
    fio;
    cin >> T;
    while (T--) {
        cin >> k;
        bool ans = false;
        for (int i = 1; i * (i + 1) / 2 < k; i++) {
            for (int j = i; j * (j + 1) / 2 < k; j++) {
                for (int l = j; l * (l + 1) / 2 < k; l++) {
                    if (tris[i] + tris[j] + tris[l] == k) {
                        cout << "1\n";
                        ans = true;
                        goto end;
                    } 
                }
            }
        }
        end:
        if (!ans)
            cout << "0\n";  
    }

    return 0;
}
