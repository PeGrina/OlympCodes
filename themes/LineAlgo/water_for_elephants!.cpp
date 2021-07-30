//
// Created by Andrey on 17.06.2021.
//
#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, tmp;
    cin >> n;
    vector <int> a(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> tmp;
            a[i] = max(tmp, a[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}
