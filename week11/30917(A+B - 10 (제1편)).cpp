#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int n;

void find_x(int& x, char target) {
    int ans;
    for (int i = 1; i <= 9; i++){
        cout << "? " << target << ' ' << i << endl;
        cin >> ans;
        if (ans == 1) {
            x = i;
            return;
        }
    }
}

int main() {
    int a = 0, b = 0;
    find_x(a, 'A');
    find_x(b, 'B');
    cout << "! " << a + b << endl;    
    
    return 0;
}
