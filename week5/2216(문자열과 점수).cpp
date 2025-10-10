#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int a, b, c;
string str1, str2;
int cache[3003][3003];

int DP(int idx1, int idx2) {
    if (idx1 == str1.length()) {
        return (str2.length() - idx2) * b;
    }
    if (idx2 == str2.length()) {
        return (str1.length() - idx1) * b;
    }
    int& ret = cache[idx1][idx2];
    if (ret != -1) return ret;

    ret = max({DP(idx1 + 1, idx2) + b, DP(idx1, idx2 + 1) + b, DP(idx1 + 1, idx2 + 1) +
    (str1[idx1] == str2[idx2] ? a : c)});
    return ret;
}

int main() {
    fio;
    memset(cache, -1, sizeof(cache));
    cin >> a >> b >> c;
    string temp1, temp2;
    cin >> temp1 >> temp2;
    if (temp1.length() >= temp2.length()) {
        str1 = move(temp1);
        str2 = move(temp2);
    } else {
        str1 = move(temp2);
        str2 = move(temp1);
    }
    cout << DP(0, 0) << '\n';

    return 0;
}
