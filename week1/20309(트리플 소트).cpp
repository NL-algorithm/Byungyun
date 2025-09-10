#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n;
int odd_arr[150'003];
int even_arr[150'003];
int main() {
    fio;
    int even_n, odd_n;
    cin >> n;
    even_n = n / 2;
    odd_n = n / 2;
    for (int i = 0; i < n / 2; i++) {
        cin >> odd_arr[i];
        cin >> even_arr[i];
    }
    if (n % 2 == 1) {
        odd_n++;
        cin >> odd_arr[n / 2];
    }
    sort(odd_arr, odd_arr + odd_n);
    sort(even_arr, even_arr + even_n);

    int odd_idx = 0;
    int even_idx = 0;
    bool success = true;
    while (true)
    {
        if (odd_arr[odd_idx] > even_arr[even_idx]) {
            success = false;
            break;
        }
        odd_idx++;
        if (odd_idx == odd_n) break;
        if (odd_arr[odd_idx] < even_arr[even_idx]) {
            success = false;
            break;
        }
        even_idx++;
        if (even_idx == even_n) break;
    }
    if (success) cout << "YES";
    else cout << "NO";
    

    return 0;
}
