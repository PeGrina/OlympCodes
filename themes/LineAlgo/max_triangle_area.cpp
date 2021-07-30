//
// Created by Andrey on 17.06.2021.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, x1 = 1001, x2 = -1001, y3 = 0, y, x;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        if (abs(y) > y3)
            y3 =abs(y);
        if (y != 0)
            continue;
        if (x < x1)
            x1 = x;
        if (x > x2)
            x2 = x;
    }
    cout << (x2 - x1)*y3/2;
}