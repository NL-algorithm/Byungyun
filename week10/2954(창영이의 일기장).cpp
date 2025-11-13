#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

string x;
string_view targets[5] = {"apa", "epe", "ipi", "opo", "upu"};

bool check(string_view sv) {
    if (sv.length() < 3) {
        return 0;
    }
    for (const auto& t : targets) {
        if (sv == t) {
            return true;
        }
    }
    return false;
}

int main() {
    fio;
    getline(cin, x);
    string_view str{x};
    string ret;
    ret.reserve(102);

    for (int i = 0; i < str.length(); i++) {
        ret.push_back(str[i]);
        if (check(str.substr(i, 3))) {
            i += 2;
        }
    }

    cout << ret;

    return 0;
}
