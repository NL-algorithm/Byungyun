#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int n;

int main() {
    int a = 0, b = 0;
    int ans;
    for (int i = 1; i <= 10000; i++){
        if (i == 4957) continue;
        cout << "? A " << i << endl;
        cin >> ans;
        if (ans == 1) {
            a = i;
            break;
        }
    }
    if (a == 0) a = 4957;
    for (int i = 1; i <= 10000; i++){
        if (i == 1535) continue;
        if (i == 5156) continue;
        cout << "? B " << i << endl;
        cin >> ans;
        if (ans == 1) {
            b = i;
            break;
        }
    }
    if (b == 0) {
        b = 1535;
    }
    cout << "! " << a + b << endl;    
    
    return 0;
}
