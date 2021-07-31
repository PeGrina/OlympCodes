//
// Created by Andrey on 31.07.2021.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#define int long long

using namespace std;

signed main() {
    int n, r, ans = 0;
    cin >> n >> r;
    vector <int> sh(n);
    for (int i = 0; i < n;i++) {
        cin >> sh[i];
    }
    int i = 0, j = 1;
    while(j != n){
        if(sh[j] - sh[i] <= r){
            j++;
        }
        else {
            ans += n - j;
            i++;
        }
    }
    cout << ans;
}