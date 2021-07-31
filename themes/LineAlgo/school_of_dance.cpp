//
// Created by Andrey on 31.07.2021.
//

#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int n;
    cin >> n >> s;
    vector <int> a(n + 1), b(n);
    a[0] = 1;
    int sm = 0;
    for (char c: s) {
        sm += (c == 'a' ? 1 : -1);
        if (sm >= 0) {
            ++a[sm];
        } else{
            ++b[-sm];
        }
    }
    int ans = 0;
    for (int i: a) {
        ans += i * (i - 1) / 2;
    }
    for (int i: b) {
        ans += i * (i - 1) / 2;
    }
    cout << ans;
}