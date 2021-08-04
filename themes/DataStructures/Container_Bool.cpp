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

class Container_Bool {
public:
    vc <int> container;
    int sz = 0;
    Container_Bool (int n) {
        sz = calc_index(n);
        container.resize(sz);
    }

    static int calc_index(int i) {
        return (i - 1) / 32 + 1;
    };

    bool operator [](int i) {
        return (container[calc_index(i)] >> (i % 32)) & 1;
    }

    void set (int i) {
        container[calc_index(i)] ^= (1 << (i % 32));
    }
};

signed main()
{
    auto a = Container_Bool(1);
    a.set(1);
    a.set(2);
    cout << a[1] << ' ' << a[0] << ' ' << a[2] << '\n';
}
