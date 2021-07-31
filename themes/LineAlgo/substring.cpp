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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map <char, int> a;
    int i = 0, j = -1, best_ans = 0, best_l = 0;
    while (j < n) {
        while (j < n) {
            ++j;
            if (j == n) {
                if (j - i > best_ans) {
                    best_ans = j - i;
                    best_l = i;
                }
                break;
            }
            a[s[j]]++;
            if (a[s[j]] > k) {
                if (j - i > best_ans) {
                    best_ans = j - i;
                    best_l = i;
                }
                break;
            }
        }
        while (i < j) {
            char c = s[i]; ++i;
            a[c]--;
            if (a[c] == k)
                break;
        }
    }
    cout << best_ans << ' ' << best_l + 1;
}