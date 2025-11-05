#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

int n, m, r;

int arr[303][303];

void prt() {
    cout << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

void rotate(int level) {
    if (level == min(n, m) / 2) {
        return;
    }
    int top = level;
    int left = level;
    int bottom = n - level - 1;
    int right = m - level - 1;

    int x = r % (2 * (n + m) - 4 - level * 8);
    while (x--) {
        int temp = arr[bottom][left];
        for (int i = bottom; i > top; i--) {
            arr[i][left] = arr[i - 1][left];
        }
        for (int i = left; i < right; i++) {
            arr[top][i] = arr[top][i + 1];
        }
        for (int i = top; i < bottom; i++) {
            arr[i][right] = arr[i + 1][right];
        }
        for (int i = right; i > left + 1; i--) {
            arr[bottom][i] = arr[bottom][i - 1];
        }

        arr[bottom][left + 1] = temp;
    }

    return rotate(level + 1);
}

int main() {
    fio;
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    rotate(0);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
