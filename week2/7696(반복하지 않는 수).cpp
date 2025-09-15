#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

int arr[1'000'003];
bool used[10];
int idx = 1;
char temp[10] = {'0','0','0','0','0','0','0','0','0','0'};
int ts = 10;

bool back(int level, int target) {
    if (level == target) {
        arr[idx++] = stoi(temp);
        return idx > 1'000'000;
    }
    bool ret;
    for (int i = (level == 0); i <= 9; i++) {
        if (used[i])
            continue;
        used[i] = true;
        temp[ts - target + level] = i + '0';
        ret = back(level + 1, target);
        if (ret)
            return ret;
        used[i] = false;
    }
    return false;
}

int main() {
    fio;
    for (int i = 1; i <= 10; i++) {
        back(0, i);
        if (idx > 1'000'000) break;
    }

    int n;
    while (true) {
        cin >> n;
        if (n == 0)
            break;
        cout << arr[n] << '\n';
    }

    return 0;
}
