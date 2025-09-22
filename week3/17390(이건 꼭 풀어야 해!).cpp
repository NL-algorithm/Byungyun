#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n, q;
int arr[300'003];
int psum[300'003];
int main() {
    fio;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 1; i <= n; i++) {
        psum[i] = psum[i - 1] + arr[i - 1];
    }

    int l,r;
    while (q--) {
        cin >> l >> r;
        cout << psum[r] - psum[l - 1] << '\n';
    }

    return 0;
}
