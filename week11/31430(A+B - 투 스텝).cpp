#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
using ll = long long;

int t;

string make_hint_str(ll target) {
    string ret;
    while (1) {
        ret.push_back(target % 26 + 'a');
        target /= 26;
        if (target == 0)
            break;
    }
    if (ret.size() < 13) {
        string temp;
        temp.assign(13 - ret.size(), 'a');
        ret.append(temp);
    }
    return ret;
}

ll parse_hint_str(string_view hint) {
    ll ret = 0;
    ll pow = 1;
    for (int i = 0; i < hint.size(); i++)
    {
        ret += (hint[i] - 'a') * pow;
        pow *= 26;
    }

    return ret;
}

int main() {
    fio;
    cin >> t;

    if (t == 1) {
        ll a, b;
        cin >> a >> b;
        cout << make_hint_str(a + b);
    } else {
        string str;
        cin >> str;
        cout << parse_hint_str(str);
    }

    return 0;
}
