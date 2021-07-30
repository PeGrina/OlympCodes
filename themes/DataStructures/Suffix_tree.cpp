#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

vector <int> build_suffix_tree (string &s) {
     s += '$';
     int n = (int) s.length();
     vector <int> p(n), c(n);
     vector <pair <char, int>> a(n);
     for (int i = 0; i < n; ++i) a[i] = {s[i], i};
     sort(a.begin(), a.end());
     for (int i = 0; i < n; ++i) p[i] = a[i].second;
     c[p[0]] = 0;
     for (int i = 1; i < n; ++i) {
         if (a[i].first == a[i - 1].first) {
             c[p[i]] = c[p[i - 1]];
         } else {
             c[p[i]] = c[p[i - 1]] + 1;
         }
     }
     int k = 0;
     while ((1 << k) < n) {
         int len = (1 << k);
         vector <pair <pair <int, int>, int>> a(n);
         for (int i = 0; i < n; ++i) {
             a[i] = {{c[i], c[(i + len) % n]}, i};
         }
         sort(a.begin(), a.end());
         for (int i = 0; i < n; ++i) p[i] = a[i].second;
         c[p[0]] = 0;
         for (int i = 1; i < n; ++i) {
             if (a[i].first == a[i - 1].first) {
                 c[p[i]] = c[p[i - 1]];
             } else {
                 c[p[i]] = c[p[i - 1]] + 1;
             }
         }
         ++k;
     }
     return p;
}

signed main () {
    string s = "abbaaa";
    vector <int> tree = build_suffix_tree(s);
    for (int i: tree) {
        cout << i << ' ';
    }
}