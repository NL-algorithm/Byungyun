#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

//백트래킹 버전
//메모리 2024kb 시간 0ms

int n, m, k;
int ans[11];

int get_swap_val(string s, int i, int j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    return stoi(s);
}

void back(int num, int cnt) {
    if (cnt == k) {
        return;
    }

    string num_str = to_string(num);
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (i == 0 && num_str[j] == '0') continue;
            int val = get_swap_val(num_str, i, j);
            if (ans[cnt] < val) {
                ans[cnt] = val;
                back(val, cnt + 1);
            }
        }
    }
}

int main() {
    fio;
    string input;
    cin >> input >> k;
    m = input.size();
    if (m == 1) {
        cout << "-1";
        return 0;
    }
    fill(ans, ans + 11, -1);

    back(stoi(input), 0);

    cout << ans[k - 1];

    return 0;
}
