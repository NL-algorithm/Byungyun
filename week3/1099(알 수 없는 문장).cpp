#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define INF 10'000

using namespace std;

int n;
string sentence;
string words[51];

bool check_str(string_view a, string_view b) {
    int cnt[26] = {0, 0};
    for (char c : a)
        cnt[c - 'a']++;
    for (char c : b) {
        if (--cnt[c - 'a'] < 0)
            return false;
    }
    return true;
}

int get_str_cost(string_view a, string_view b) {
    if (!check_str(a, b))
        return INF;
    int cost = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i])
            cost++;
    }
    return cost;
}

int get_min_cost(string_view str) {
    int min_cost = INF;
    for (int i = 0; i < n; i++) {
        if (words[i].length() == str.length()) {
            min_cost = min(min_cost, get_str_cost(words[i], str));
        }
    }
    return min_cost;
}

int cost_cache[51][51];
int cache[51][51];

void preprocessing() {
    string_view temp_strv = string_view(sentence);
    for (int i = 0; i < sentence.length(); i++) {
        for (int j = i; j < sentence.length(); j++) {
            cost_cache[i][j] = get_min_cost(temp_strv.substr(i, j - i + 1));
        }
    }
}

int DP(int cur_idx, int st_idx) {
    if (cur_idx == sentence.length()) {
        if (st_idx == cur_idx)
            return 0;
        return INF;
    }
    int &ret = cache[cur_idx][st_idx];
    if (ret != -1)
        return ret;

    ret = min(DP(cur_idx + 1, cur_idx + 1) + cost_cache[st_idx][cur_idx], DP(cur_idx + 1, st_idx));

    return ret;
}

int main() {
    fio;
    memset(cache, -1, sizeof(cache));
    cin >> sentence >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    preprocessing();

    int res = DP(0, 0);
    if (res >= INF)
        cout << -1;
    else
        cout << res;

    return 0;
}
