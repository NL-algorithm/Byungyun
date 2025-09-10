#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int n;
int main() {
    fio;
    cin >> n;

    

    return 0;
}

/*
1 ~ 9 (한자리수) 각 1씩 (0만)
10 ~ 99 (두자리수) (0 ~ 9) * 9 + (1 ~ 9) * 10
1 ~ 99 (0 ~ 9) * 10 + (1 ~ 9) * 10 - (0) (0만 1빼주기)
*/