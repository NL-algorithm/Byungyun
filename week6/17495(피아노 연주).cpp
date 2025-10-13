#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
int n;
int sheet[1005];
int cache[1005][1005];
pair<int, int> his[1005][1005];

int pitch_to_int(string_view pitch) {
    static const map<string_view, int> pitch_map = {
        {"A", 9}, 
        {"A#", 10}, 
        {"B", 11}, 
        {"B#", 12},
        {"C", 0}, 
        {"C#", 1}, 
        {"D", 2}, 
        {"D#", 3}, 
        {"E", 4}, 
        {"E#", 5},
        {"F", 5}, 
        {"F#", 6}, 
        {"G", 7}, 
        {"G#", 8}};
    int octave = pitch[1] - '0';
    string s;
    if (pitch.length() == 3) 
        s = {pitch[0],pitch[2]};
    else
        s = {pitch[0]};
    int val = pitch_map.find(s)->second;
    return octave * 12 + val;
}

int DP(int lhand, int rhand) {
    int last = max(lhand, rhand);
    if (last == n + 1)
        return 0;

    int &ret = cache[lhand][rhand];
    if (ret != -1)
        return ret;

    int lhand_go = DP(last + 1, rhand) + abs(sheet[last + 1] - sheet[lhand]);
    int rhand_go = DP(lhand, last + 1) + abs(sheet[last + 1] - sheet[rhand]);
    if (lhand_go < rhand_go) {
        ret = lhand_go;
        his[lhand][rhand] = {last + 1, rhand};
    } else {
        ret = rhand_go;
        his[lhand][rhand] = {lhand, last + 1};
    }

    return ret;
}

int main() {
    fio;
    memset(cache, -1, sizeof(cache));
    string t1,t2;
    int l,r;
    cin >> t1 >> t2 >> n;
    sheet[0] = pitch_to_int(t1);
    sheet[1] = pitch_to_int(t2);
    for (int i = 2; i < n + 2; i++) {
        cin >> t1;
        sheet[i] = pitch_to_int(t1);
    }
    cout << DP(0, 1) << '\n';
    pair<int, int> cur = {0, 1};
    for (int i = 0; i < n; i++) {
        auto nxt = his[cur.first][cur.second];
        if (cur.first == nxt.first) {
            cout << 2 << ' ';
        } else {
            cout << 1 << ' ';
        }
        cur = nxt;
    }

    return 0;
}
