#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

string A, B;

bool solve(string_view S) {
    if (S.size() < A.size()) return false;
    if (A.size() == S.size()) {
        if (A == S) return true;
    }
    if (S.back() == 'A') {
        if (solve(string_view(S.begin(), S.end() - 1)))
            return true;
    }
    else {
        string copy_S(S.rbegin(), S.rend());
        if (solve(string_view(copy_S.begin() + 1, copy_S.end())))
            return true;
    }
    return false;
}

int main() {
    fio;
    cin >> A >> B;
    cout << solve(B);

    return 0;
}
