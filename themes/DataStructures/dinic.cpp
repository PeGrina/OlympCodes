/*
 * @name Dinic algorithm
 * @description Algorithm for flow searching in O(n^2m)
 * */
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
#define sz(a) (int)a.size()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define pii pair <int, int>
#define vec pt
#define int long long
#define all(a) a.begin(),a.end()

const int N = 1001, maxk = 21, inf = 1e18, mod = 1e9 + 7;
const int bit = 61;
const ld eps = 1e-6;

struct Flow {
    struct edge {
        int u, v, f, c;
    };
    int n, s, t;
    vc <int> d, pt;
    vc <edge> edges;
    vc <vc <int>> g;
    void add_edge (int u, int v, int c) {
        edge e1, e2;
        e1 = {u, v, 0, c}; e2 = {v, u, 0, 0};
        g[u].pb(sz(edges)); edges.pb(e1);
        g[v].pb(sz(edges)); edges.pb(e2);
    }
    bool bfs () {
        queue <int> q;
        q.push(s);
        d.assign(n, -1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i: g[u]) {
                int v = edges[i].v;
                if (d[v] == -1 && edges[i].f < edges[i].c) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        if (d[t] == -1) {
            return false;
        }
        return true;
    }
    int dfs (int u, int f) {
        if (f == 0) return 0;
        if (u == t) return f;
        for (; pt[u] < sz(g[u]); ++pt[u]) {
            int i = g[u][pt[u]];
            int v = edges[i].v;
            if (d[v] != d[u] + 1) continue;
            int got = dfs(v, min(f, edges[i].c - edges[i].f));
            if (got != 0) {
                edges[i].f += got;
                edges[i ^ 1].f -= got; // reversed edge
                return got;
            }
        }
        return 0;
    }
    Flow(int n, int s = 0, int t = -1): n(n), s(s), t(t) {
        if (t == -1) {
            this->t = n - 1;
        }
        pt.resize(n);
        d.resize(n);
        g.resize(n);
    }
    int start () {
       int answer = 0;
       while (1) {
           if (!bfs()) {
               break;
           }
           pt.assign(n, 0);
           int got = 0;
           do {
               got = dfs(s, inf);
               answer += got;
           } while (got);
       }
       return answer;
    }
};

void solve () {
    int n, m;
    cin >> n >> m;
    Flow flow = Flow(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        flow.add_edge(u - 1, v - 1, c);
    }
    cout << flow.start() << '\n';
}

/*
 * For testing
6 6
1 2 1
1 3 1
2 4 1
3 5 1
4 6 1
5 6 1

Ans: 2
 * */

/* Starting and precalcing */
signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
