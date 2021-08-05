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

ifstream inf ("input.txt");
ofstream outf ("output.txt");

class List {
public:
    struct node {
        int to, from;
    };
    vc <node> a;

    void erase (int i) {
        auto [to, from] = a[i];
        a[from].to = to;
        a[to].from = from;
    }

    int query (int i) {
        return a[i].to + 1;
    }

    List (int n) {
        a.resize(n);
        a[0].from = -2;
        for (int i = 1; i < n; ++i) {
            a[i - 1].to = a[i].from = i;
        }
        a.back().to = -2;
    }
};

signed main()
{
    int n, q;
    inf >> n >> q;
    auto a = List(n);
    char c; int i;
    while (q--) {
        inf >> c >> i;
        if (c == '-') {
            a.erase(i - 1);
        } else {
            outf << a.query(i - 1) << '\n';
        }
    }
}
