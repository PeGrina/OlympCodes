//
// Created by Andrey on 17.06.2021.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N = 0, points, first = 0, second = 0;
    cin >> N;
    for (int i = 0; i < N;i++) {
        cin >> points;
        if(points > first){
            second = first;
            first = points;
        }
        else if(points > second && points != first){
            second = points;
        }
    }
    cout << second;
}