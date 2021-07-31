#include <iostream>
#include <vector>
#define int long long

using namespace std;

vector <int> t, a;

void init (int n) {
    t.resize(n * 4);
    build(1, 0, n - 1);
}

int combine (int a, int b) {
    return a + b;
}

void build (int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

int query (int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (tl == l && tr == r) {
        return t[v];
    } else {
        int tm = (tl + tr) / 2;
        return combine(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
    }
}

void update (int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[v] = val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, val);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

signed main () {
    /* Simple task for sum */
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
            cout << query(1, 0, n - 1, l, r) << '\n';
        } else {
            int pos, val;
            cin >> pos >> val; --pos;
            update(1, 0, n - 1, pos, val);
        }
    }
}