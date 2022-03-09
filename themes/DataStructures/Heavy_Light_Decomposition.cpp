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
const int maxn = 3e5, logn = 20, inf = 1e9 + 7;

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
    euler.pb(u);
    tim++;
    for (int i = 0; i < sz(g[u]); ++i) {
        int v = g[u][i];
        if (v != p) {
            if (i != 0) {
                en[v] = v;
                dfs(v, u, lst, 1);
            } else {
                en[v] = en[u];
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
        t[v] = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm, tr);
}

void upd (int v, int tl, int tr, int l, int r, int x) {
    if (r <= tl || tr <= l) return;
    if (l <= tl && tr <= r) {
        t[v] += x;
        return;
    }
    int tm = (tl + tr) / 2;
    upd(v * 2, tl, tm, l, r, x);
    upd(v * 2 + 1, tm, tr, l, r, x);
}

int get (int v, int tl, int tr, int i) {
    if (tr - tl == 1) return t[v];
    int tm = (tl + tr) / 2;
    if (i < tm) return get(v * 2, tl, tm, i) + t[v];
    return get(v * 2 + 1, tm, tr, i) + t[v];
}

int get (int i) {
    return get(1, 0, n, ip[i]);
}

void up (int &u, int &v, int &x) {
    while (!is_ancestor(en[u], v)) {
        upd(1, 0, n, ip[en[u]], ip[u] + 1, x);
        u = pr[en[u]];
    }
}

void upd (int u, int v, int x) {
    up(u, v, x);
    up(v, u, x);
    if (!is_ancestor(u, v)) swap(u, v);
    upd(1, 0, n, ip[u], ip[v] + 1, x);
}

void solve () {
    cin >> n;
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
        if (c == '+') {
            int u, v, x;
            cin >> u >> v >> x; --u; --v;
            upd(u, v, x);
        } else {
            int i;
            cin >> i; --i;
            cout << get(i) << '\n';
        };
    }
}

/* Starting and precalcing */
signed main() {
    // freopen("sequence.in","r",stdin);freopen("sequence.out","w",stdout);
    fast;
    solve();
    return 0;
}
