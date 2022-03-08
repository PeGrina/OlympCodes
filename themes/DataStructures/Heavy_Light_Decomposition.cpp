/* Includes */
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>

/* Using libraries */
using namespace std;

/* Defines */
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ld long double
#define pb push_back
#define vc vector
#define int long long
#define sz(a) (int)a.size()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define pii pair <int, int>
#define vec pt

/* Constants */
const ld eps = 1e-10;
const int maxn = 1e5, logn = 20, inf = 1e9 + 7;

vc <int> g[maxn];
vc <int> euler;
int ip[maxn], en[maxn], ip2[maxn], ip_en[maxn], pr[maxn];
int a[maxn], tin[maxn], tout[maxn], dp[maxn], Time = 0, tim = 0;

void precalc (int u, int p = -1) {
    dp[u] = 1;
    for (int v: g[u]) {
        if (v != p){
            pr[v] = u;
            precalc(v, u);
            dp[u] += dp[v];
        }
    }
    int mx = 0, i1 = 0;
    for (int i = 0; i < sz(g[u]); ++i) {
        int v = g[u][i];
        if (v == p) continue;
        if (dp[v] > mx) {
            mx = dp[v];
            i1 = i;
        }
    }
    if (!g[u].empty())
        swap(g[u][0], g[u][i1]);
}

void dfs (int u, int p = -1, int lst = 0, bool f = false) {
    tin[u] = Time++;
    ip[u] = tim;
    ip2[tim] = u;
    if (f) {
        lst = ip[u];
        ip_en[ip[u]] = u;
    }
    en[u] = lst;
    euler.pb(u);
    tim++;
    for (int i = 0; i < sz(g[u]); ++i) {
        int v = g[u][i];
        if (v != p) {
            if (i != 0) {
                dfs(v, u, lst, 1);
            } else {
                dfs(v, u, lst, 0);
            }
        }
    }
    tout[u] = Time++;
}

bool is_ancestor (int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int t[maxn * 4], n;

void build (int v, int tl, int tr) {
    if (tr - tl == 1) {
        t[v] = a[ip2[tl]];
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm, tr);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

void upd (int v, int tl, int tr, int i) {
    if (tr - tl == 1) {
        t[v] = a[ip2[i]];
        return;
    }
    int tm = (tl + tr) / 2;
    if (i < tm) upd(v * 2, tl, tm, i);
    else upd(v * 2 + 1, tm, tr, i);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int get (int v, int tl, int tr, int l, int r) {
    if (tr <= l || r <= tl) return 0;
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    return max(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm, tr, l, r));
}

void upd1 (int i, int x) {
    a[i] = x;
    upd(1, 0, n, ip[i]);
}

int get (int u, int v, int f = 0) {
    int res = 0;
    while (!is_ancestor(ip_en[en[u]], v)) {
        res = max(res, get(1, 0, n, ip[ip_en[en[u]]], ip[u] + 1));
        if (u == ip_en[en[u]]) u = pr[u];
        else u = ip_en[en[u]];
    }
    while (!is_ancestor(ip_en[en[v]], u)) {
        res = max(res, get(1, 0, n, ip[ip_en[en[v]]], ip[v] + 1));
        if (v == ip_en[en[v]]) v = pr[v];
        else v = ip_en[en[v]];
    }
    if (!is_ancestor(u, v) && !is_ancestor(v, u)) {
        if (is_ancestor(pr[u], v)) {
            u = pr[u];
            res = max(res, get(1, 0, n, ip[u], ip[v] + 1));
        } else {
            v = pr[v];
            res = max(res, get(1, 0, n, ip[v], ip[u] + 1));
        }
    } else {
        if (is_ancestor(u, v)) {
            res = max(res, get(1, 0, n, ip[u], ip[v] + 1));
        } else {
            res = max(res, get(1, 0, n, ip[v], ip[u] + 1));
        }
    }
    return res;
}

void solve () {
    cin >> n;
    forn (i, n) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v; --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    precalc(0);
    dfs(0, -1, 0, false);
    build(1, 0, n);
    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        if (c == '!') {
            int i, h;
            cin >> i >> h;
            upd1(i - 1, h);
        } else {
            int i, j;
            cin >> i >> j; --i; --j;
            cout << get(i, j, 0) << '\n';
        }
    }
}

/* Starting and precalcing */
signed main() {
    // freopen("sequence.in","r",stdin);freopen("sequence.out","w",stdout);
    // fast;
    solve();
    return 0;
}
/*
3
1 1 1
1 2
2 3
2
! 2 2
? 3 3
 * */
