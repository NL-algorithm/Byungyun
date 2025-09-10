#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
int n, m, k;
int cache[1'000'003][11];

int my_swap(string s, int i, int j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    return stoi(s);
}

int DP(int num, int cnt) {
    if (cnt == 0) {
        return cache[num][cnt] = num;
    }
    int &ret = cache[num][cnt];
    if (ret != -1)
        return ret;

    auto s = to_string(num);
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (i == 0 && s[j] == '0') continue;
            ret = max(ret, DP(my_swap(s, i, j), cnt - 1));
        }
    }

    return ret;
}

int main() {
    fio;
    memset(cache, -1, sizeof(cache));
    string input;
    cin >> input >> k;
    m = input.size();
    n = stoi(input);
    cout << DP(n, k);

    return 0;
}
