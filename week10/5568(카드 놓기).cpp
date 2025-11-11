#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

string arr[10];
int n, k;
int ans;
set<string> ans_set;
bool use[10];

void back(int idx, string str) {
    if(idx == k) {
        if (ans_set.find(str) == ans_set.end()) {
            ans++;
            ans_set.insert(str);
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!use[i]) {
            use[i] = true;
            back(idx + 1, str + arr[i]);
            use[i] = false;
        }
    }
}

int main() {
    fio;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    back(0, string());
    cout << ans;

    return 0;
}
