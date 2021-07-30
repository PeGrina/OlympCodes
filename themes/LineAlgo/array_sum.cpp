//
// Created by Andrey on 17.06.2021.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
	int i=0, i1, maxsum = -1, j1, N, s, sum = 0;
	cin >> N;
	for (int l = 0; l < N; l++) {
		cin >> s;
		sum += s;
		if(sum > maxsum){
			maxsum = sum;
			i1 = i;
			j1 = l;
		}
		if(sum <= 0)
			sum = 0,
			i = l+1;
	}
	cout << i1 + 1 << " " << j1 + 1;
}