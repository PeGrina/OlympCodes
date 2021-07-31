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
#define kill(text) cout << text << '\n'; return 0
#define ld long double
#define sz(a) ((int)(a.size()))
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

int gcd (int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n, w, l, r;
    cin >> n >> w;
    vector <pair <int, int>> a(n + 2);
    cin >> l >> r;
    if (r - l < w) {
        cout << -1;
        return 0;
    }
    a[0].first = l; a[0].second = -1;
    a[n + 1].first = r; a[n + 1].second = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int j = 0, t = -1, x = 0, y = n + 1;
    vector <int> answer;
    for (int i = 1; i <= n; ++i)
        answer.push_back(a[i].second);
    while (j <= n && t == -1) {
        int i = 1;
        do {
            if (abs(a[i - 1].first - a[i + j].first) >= w) {
                t = 0;
                x = i - 1;
                y = i + j;
                break;
            }
            ++i;
        } while (i + j <= n + 1);
        ++j;
    }
    if (t == 0) {
        cout << y - x - 1 << '\n';
        for (int i = x + 1; i < y; ++i) {
            cout << a[i].second << '\n';
        }
    }
}