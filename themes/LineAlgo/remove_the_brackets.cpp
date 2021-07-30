//
// Created by Andrey on 17.06.2021.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int counter = 0;
    queue <char> sk;
    for (int i = 0; i < s.size();i ++) {
        if (s[i] == '(') {
            sk.push('(');
        }
        else {
            if(!sk.empty()){
                sk.pop();
                continue;
            }
            counter++;
        }
    }
    if(!sk.empty()){
        counter += sk.size();
    }
    cout << counter;
}