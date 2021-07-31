//
// Created by Andrey on 31.07.2021.
//

#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define pii pair <int, int>
#define forn for(int i = 0; i < n; ++i)
#define vii vector<pii>

using namespace std;

map <pii, bool> crds;

bool request(int l, int r) {
    if (crds.count({l, r}) != 0) {
        return crds[{l, r}];
    } else {
        string ans;
        cout << "? " << l + 1 << ' ' << r + 1 << endl;
        cin >> ans;
        bool is = ans[0] == 'Y';
        crds[{l, r}] = is;
        return is;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <char> d(n, '?');
    stack <int> s;
    forn {
        if (s.empty()) {
            s.push(i);
        } else {
            if(request(s.top(), i)) {
                d[s.top()] = '(';
                d[i] = ')';
                s.pop();
            } else {
                s.push(i);
            }
        }
    }
    cout << "! ";
    forn {
        cout << d[i];
    }
}