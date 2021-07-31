//
// Created by Andrey on 31.07.2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#include <set>
#include <map>

#define int long long
#define ld long double
#define sz(a) ((int)(a.size()))
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;


signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector <vector <int> > a(n, vector <int>(m)), sat(n + 1, vector <int>(m + 1));
    forn (i, n) {
        forn (j, m) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sat[i][j] = a[i - 1][j - 1] - sat[i - 1][j - 1] + sat[i][j - 1] + sat[i - 1][j];
        }
    }
    int x, y, x2, y2;
    forn (i, q) {
        cin >> x >> y >> x2 >> y2;
        cout << sat[x2][y2] + sat[x - 1][y - 1] - sat[x2][y - 1] - sat[x - 1][y2] << '\n';
    }
}