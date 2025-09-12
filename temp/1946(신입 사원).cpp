#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
using pr = pair<int,int>;
int T;
pr arr[100'003];
int main() {
    fio;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr, arr + n);
        int ans = 0, sec_min = 1000000;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].second < sec_min) {
                ans++;
                sec_min = arr[i].second;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
