#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stack>
#include <map>

#define fast ios::sync_with_stdio(false); cin.tie(0)
#define vc vector
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define sz(a) (int) a.size()
#define forn(i, n) for(int i = 0; i < n; ++i)

using namespace std;


class DSU {
public:
    vc <int> p, r;

    DSU (int n) {
        p.resize(n);
        r.resize(n);
        forn (i, n) {
            p[i] = i;
            r[i] = 1;
        }
    }

    int find (int u) {
        if (u == p[u])
            return u;
        return p[u] = find(p[u]);
    }

    bool unite (int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (r[u] < r[v]) swap(u, v);
        p[v] = u;
        r[u] += r[v];
        return true;
    }

    bool check (int u, int v) {
        return find(u) == find(v);
    }
};

signed main()
{
    auto a = DSU(3);
    cout << a.find(0) << '\n';
    a.unite(1, 0);
    cout << a.find(0) << '\n';
    a.unite(0, 2);
    cout << a.find(2) << '\n';
}
