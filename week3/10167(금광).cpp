#include <bits/stdc++.h>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define INF 1100000000LL

using namespace std;
using ll = long long int;

struct Point {
    int x, y, w;
} points[3003];

vector<pair<int, int>> ziped[3003];

struct Sums {
    ll lmax, rmax, tsum, max;
    Sums() = default;
    explicit Sums(ll x) : lmax(x), rmax(x), tsum(x), max(x) {}
};

Sums make_sums(const Sums &f, const Sums &s) {
    Sums cur;
    cur.lmax = max(f.tsum + s.lmax, f.lmax);
    cur.rmax = max(s.tsum + f.rmax, s.rmax);
    cur.tsum = s.tsum + f.tsum;
    cur.max = max(max(f.max, s.max), f.rmax + s.lmax);
    return cur;
}

class segment_tree {
    int n;
    vector<Sums> seg;

  private:
    Sums init(const vector<ll> &base, int node, int left, int right) {
        if (left == right) {
            return seg[node] = Sums(base[left]);
        }
        int mid = (left + right) / 2;
        return seg[node] = make_sums(init(base, node * 2, left, mid), init(base, node * 2 + 1, mid + 1, right));
    }
    Sums query(const int left, const int right, int node, int node_left, int node_right) {
        if (left > node_right || right < node_left)
            return Sums(-INF);
        if (left <= node_left && node_right <= right)
            return seg[node];
        int mid = (node_left + node_right) / 2;
        const Sums &left_query = query(left, right, node * 2, node_left, mid);
        const Sums &right_query = query(left, right, node * 2 + 1, mid + 1, node_right);
        if (left_query.tsum == -INF)
            return right_query;
        if (right_query.tsum == -INF)
            return left_query;
        return make_sums(left_query, right_query);
    }
    Sums update(const int idx, const ll new_value, int node, int node_left, int node_right) {
        if (idx < node_left || node_right < idx) {
            return seg[node];
        }
        if (node_left == node_right) {
            // update를 합으로 바꿔줌
            return seg[node] = Sums(seg[node].max + new_value);
        }
        int mid = (node_left + node_right) / 2;
        return seg[node] = make_sums(update(idx, new_value, node * 2, node_left, mid),
                                     update(idx, new_value, node * 2 + 1, mid + 1, node_right));
    }

  public:
    segment_tree(int size) {
        this->n = size;
        seg.resize(size * 4);
        // init(base, 1, 0, n - 1);
    }
    ll query(const int left, const int right) {
        return query(left, right, 1, 0, n - 1).max;
    }
    void update(const int idx, const ll new_value) {
        update(idx, new_value, 1, 0, n - 1);
    }
};

int n, x, y, w;

pair<int, int> zip() {
    sort(points, points + n, [](const Point &a, const Point &b) {
        return a.x < b.x;
    });
    int xidx = 0;
    for (int i = 0; i < n; i++) {
        int cur_x = points[i].x;
        while (cur_x == points[i].x && i < n) {
            points[i].x = xidx;
            i++;
        }
        xidx++;
        i--;
    }
    sort(points, points + n, [](const Point &a, const Point &b) {
        return a.y < b.y;
    });
    int yidx = 0;
    for (int i = 0; i < n; i++) {
        int cur_y = points[i].y;
        while (cur_y == points[i].y && i < n) {
            ziped[yidx].emplace_back(points[i].x, points[i].w);
            i++;
        }
        yidx++;
        i--;
    }
    return {xidx, yidx};
}

int main() {
    fio;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> w;
        points[i] = {x, y, w};
    }
    auto [x_size, y_size] = zip();

    ll ans = -3'300'000'000'000LL;
    for (int i = 0; i < y_size; i++) {
        segment_tree seg(x_size);
        for (int j = i; j < y_size; j++) {
            for (auto [x, w] : ziped[j])
                seg.update(x, w);
            ans = max(ans, seg.query(0, x_size - 1));
        }
    }
    cout << ans;

    return 0;
}