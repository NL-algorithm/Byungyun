#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
int n;

struct human {
    string name;
    string pattern;
    int score = 0;
    int idx = 0;

    void increment() {
        idx = (idx + 1) % pattern.size();
    }

    void comp(char c) {
        if (c == pattern[idx])
            score++;
        increment();
    }
};

int main() {
    fio;
    string pr;
    cin >> n >> pr;
    human humans[3] = {
        {"Adrian", "ABC", 0, 0},
        {"Bruno", "BABC", 0, 0},
        {"Goran", "CCAABB", 0, 0}
    };
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < 3; j++)
            humans[j].comp(pr[i]);

    int mx = max({humans[0].score, humans[1].score, humans[2].score});
    cout << mx << '\n';
    for (int i = 0; i < 3; i++)
        if (humans[i].score == mx) cout << humans[i].name << '\n';

    return 0;
}
