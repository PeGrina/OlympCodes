#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stack>
#include <map>
#include <math.h>
#include <set>
#include <unordered_set>
#include <queue>
#include <bitset>
#include <iomanip>

#define int int
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define vc vector
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define sz(a) (int) a.size()
#define forn(i, n) for(int i = 0; i < n; ++i)
const int k = 26;
using namespace std;

struct node {
    int next[k], go[k];
    int link = -1;
    int p = -1;
    int leaf = 0;
    int c = -1;
    node () {
        forn (i, k) next[i] = go[i] = -1;
    }
};

struct AchoKorasik {
    vc <node> t;
    int sz;
    AchoKorasik() {
        sz = 1;
        t.resize(1);
        t[0].p = t[0].link = 0; // Root parent and suffix link iss himself
    }

    void add_string (string &s) {
        int pos = 0; // Starting from root
        for (char tmp: s) {
            int c = tmp - 'a';
            if (t[pos].next[c] == -1) {
                node tmp;
                tmp.p = pos;
                tmp.c = c;
                t[pos].next[c] = sz++;
                t.pb(tmp);
            }
            pos = t[pos].next[c];
        }
        t[pos].leaf++;
    }

    int go (int u, int c) {
        if (t[u].go[c] == -1) {
            if (t[u].next[c] != -1)
                t[u].go[c] = t[u].next[c];
            else {
                if (u == 0)
                    t[u].go[c] = c;
                else
                    t[u].go[c] = go(link(u), c);
            }
        }
        return t[u].go[c];
    }

    int link (int u) {
        if (t[u].link == -1) {
            if (u == 0 || t[u].p == 0)
                t[u].link = 0;
            else
                t[u].link = go(link(t[u].p), t[u].c);
        }
        return t[u].link;
    }
};

void solve() {
    AchoKorasik t;
    string s, tmp;
    cin >> s;
    int n;
    cin >> n;
    forn (i, n) {
        cin >> tmp;
        t.add_string(tmp);
    }
    int pos = 0;
    for (int i = 0; i < sz(s); ++i) {
        int c = s[i] - 'a';
        while (t.t[pos].next[c] == -1) {
            pos = t.link(pos);
        }
        pos = t.t[pos].next[c];
    }
}

signed main()
{
    fast;
    int _ = 1;
    // cin >> _;
    while (_--) solve();
    return 0;
}

/*
3
1 2 2
3 2 1
2 4 3
 */
