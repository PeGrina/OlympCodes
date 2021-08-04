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


class Trie {
public:
    struct node {
        int next[26];
        bool leaf = false;
        node () {
            forn (i, 26) next[i] = -1;
        }
    };
    vc <node> tree;
    int sz = 0;
    Trie () {
        tree.resize(1);
        sz = 1;
    }

    void add (string &s) {
        int pos = 0;
        for (int i = 0; i < sz(s); ++i) {
            int c = s[i] - 'a';
            if (tree[pos].next[c] == -1) {
                node tmp;
                tree[pos].next[c] = sz++;
                tree.pb(tmp);
            }
            pos = tree[pos].next[c];
        }
        tree[pos].leaf = true;
    }

    bool check (string &s) {
        int pos = 0;
        for (int i = 0; i < sz(s); ++i) {
            int c = s[i] - 'a';
            if (tree[pos].next[c] == -1) {
                return false;
            }
            pos = tree[pos].next[c];
        }
        return tree[pos].leaf;
    }
};

signed main()
{
    auto a = Trie();
    string test1 = "aba", test2 = "aaa";
    string is = "a", is2 = "aaa";
    a.add(test1);
    a.add(test2);
    cout << a.check(is) << ' ' << a.check(is2) << '\n';
}
