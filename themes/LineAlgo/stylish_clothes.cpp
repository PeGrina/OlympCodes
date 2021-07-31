//
// Created by Andrey on 31.07.2021.
//

#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int n, m;
    cin >> n;
    vector <int> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    cin >> m;
    vector <int> s(m);
    for (int i = 0; i < m; ++i) {
        cin >> s[i];
    }
    int i = 0, j = 0;
    int ibest = 0, jbest = 0;
    while (i < n && j < m) {
        if (abs(f[i] - s[j]) < abs(f[ibest] - s[jbest])) {
            ibest = i;
            jbest = j;
        }
        if (f[i] < s[j]) {
            ++i;
        } else if (f[i] > s[j]) {
            ++j;
        } else {
            cout << f[i] << " " << s[j];
            return 0;
        }
    }
    cout << f[ibest] << " " << s[jbest];
}