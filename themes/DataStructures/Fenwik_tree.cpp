#include <iostream>
#include <vector>
#define int long long

using namespace std;

vector <int> t, a;

void inc (int i, int d) {
    int n = (int) a.size();
    for (; i < n; i += (i&-i)) {
        t[i] += d;
    }
}

int query (int r) {
    int res = 0;
    for (; r >= 0; r -= (r&-r)) {
        res += t[r];
    }
    return res;
}

void init (int n) {
    t.resize(n, 0);
    for (int i = 0; i < n; ++i)
        inc(i, a[i]);
}

signed main () {
    /* Simple code for sum_tree */
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    init(n);
    int Q;
    for (int i = 0; i < q; ++i) {
        cin >> Q;
        if (Q == 1) {
            int l, r;
            cin >> l >> r; --l; --r;
            cout << (query(r) - query(l - 1)) << '\n';
        } else {
            int pos, val;
            cin >> pos >> val; --pos;
            inc(pos, val - a[pos]);
            a[pos] = val;
        }
    }
}