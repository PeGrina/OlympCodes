//
// Created by Andrey on 31.07.2021.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <math.h>
#include <algorithm>
#define int long long

using namespace std;

struct product {
    int col, id;
};

vector <vector<int>> a(4);
struct point {
    int fi = 0,
            se = 0,
            th = 0,
            fo = 0;
    int n1,
            n2,
            n3,
            n4;
    void send(int n1, int n2, int n3, int n4) {
        this->n1 = n1;
        this->n2 = n2;
        this->n3 = n3;
        this->n4 = n4;
    }
    bool check(){
        if(this->fi < this->n1 && this->se < this->n2 && this->th < this->n3 && this->fo < this->n4){
            return true;
        }
        return false;
    }
};
int main() {
    int n1, n2, n3, n4, val, maxn = 1e5+1;
    vector <int> ans(4);
    point points;
    cin >> n1;
    for (int i = 0; i < n1;i++) {
        cin >> val;
        a[0].push_back(val);
    }
    sort(a[0].begin(), a[0].end());
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cin >> val;
        a[1].push_back(val);
    }
    sort(a[1].begin(), a[1].end());
    cin >> n3;
    for (int i = 0; i < n3; i++) {
        cin >> val;
        a[2].push_back(val);
    }
    sort(a[2].begin(), a[2].end());
    cin >> n4;
    for (int i = 0; i < n4; i++) {
        cin >> val;
        a[3].push_back(val);
    }
    sort(a[3].begin(), a[3].end());
    points.send(n1, n2, n3, n4);
    while (points.check()) {
        int mn = min({ a[0][points.fi], a[1][points.se], a[2][points.th], a[3][points.fo] }), mx = max({ a[0][points.fi], a[1][points.se], a[2][points.th], a[3][points.fo] });
        if(mx-mn < maxn){
            maxn = mx - mn;
            ans = { a[0][points.fi], a[1][points.se], a[2][points.th], a[3][points.fo] };
        }
        if(a[0][points.fi] == mn){
            points.fi++;
        }else if(a[1][points.se] == mn){
            points.se++;
        }
        else if (a[2][points.th] == mn) {
            points.th++;
        }
        else if (a[3][points.fo] == mn) {
            points.fo++;
        }
    }
    for (int i = 0; i < 4; i++) {
        cout << ans[i] << " ";
    }
}