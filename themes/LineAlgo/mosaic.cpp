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
#define int long long
using namespace std;
long long const INF = 1e12;
struct product {
    int col, id;
};
struct pazl {
    int x,
            y;
    int shx = -1,
            shy = -1;
};
int main() {
    int n, x, y, p;
    cin >> n;
    vector <pazl> moz(n);
    moz[0].shx = -1;
    moz[0].shy = -1;
    cin >> moz[0].x >> moz[0].y;
    for (int i = 1; i < n; i++) {
        cin >> moz[i].x >> moz[i].y;
        if(moz[i - 1].x != moz[i].x){
            moz[i].shx = i - 1;
        }
        else {
            moz[i].shx = moz[i - 1].shx;
        }
        if (moz[i - 1].y != moz[i].y) {
            moz[i].shy = i - 1;
        }
        else {
            moz[i].shy = moz[i - 1].shy;
        }
    }
    int k, a, b;
    char el, unel;
    cin >> k;
    for (int test = 0; test < k; test++) {
        cin >> a >> b;
        if(moz[b-1].shx == -1 || moz[b - 1].shy == -1 || moz[b-1].shx < a-1 || moz[b - 1].shx > b-1){
            cout << "0 0" << endl;
        }else if(moz[b - 1].shx >= a - 1 && moz[b - 1].shx <= b - 1){
            if(moz[b - 1].shx == moz[b - 1].shy){
                cout << b << " " << moz[b - 1].shx + 1 << endl;
            }
            else {
                if(moz[moz[b-1].shx].x != moz[b - 1].x && moz[moz[b - 1].shx].y != moz[b - 1].y){
                    cout << b << " " << moz[b - 1].shx + 1 << endl;
                }
                else if(moz[moz[b - 1].shy].y != moz[b - 1].y && moz[moz[b - 1].shy].x != moz[b - 1].x){
                    cout << b << " " << moz[b - 1].shy + 1 << endl;
                }
                else if (moz[moz[b - 1].shy].y != moz[moz[b - 1].shx].y && moz[moz[b - 1].shy].x != moz[moz[b - 1].shx].x) {
                    cout << moz[b - 1].shx + 1 << " " << moz[b - 1].shy + 1 << endl;
                }
            }
        }
    }
}