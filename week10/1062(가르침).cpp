#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

int n, k;
int words[51];
int bits, ans;

int make_bit(string_view target) {
    int ret = 0;
    for (char x : target) {
        ret |= 1 << (x - 'a');
    }
    return ret;
}

int count_know_word() {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if ((words[i] & bits) == words[i])
            ret++;
    }
    return ret;
}

void back(int idx, int before) {
    if (idx == k - 5) {
        ans = max(ans, count_know_word());
        return;
    }
    for (int i = before + 1; i < 26; i++) {
        if (bits & (1 << i)) continue;
        bits |= 1 << i;
        back(idx + 1, i);
        bits &= ~(1 << i);
    }
}

int main() {
    fio;
    cin >> n >> k;
    if (k < 5) {
        cout << 0;
        return 0;
    }
    bits = make_bit("antic");
    string input;
    string_view temp;
    for (int i = 0; i < n; i++) {
        cin >> input;
        temp = input;
        words[i] = make_bit(temp.substr(4, input.length() - 8));
    }

    back(0, 0);
    cout << ans;

    return 0;
}

// a n t i c