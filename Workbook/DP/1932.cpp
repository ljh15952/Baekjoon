#include <bits/stdc++.h>

using namespace std;


int n;

int d[501][501];
int a[501][501];

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}

	d[1][1] = a[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j];
		}
	}

	cout << *max_element(d[n] + 1, d[n] + n + 1) << '\n';

	/*
	d[1][0] = d[0][0] + a[1][0];
	d[1][1] = d[0][0] + a[1][1];

	d[2][0] = d[1][0] + a[2][0];
	d[2][1] = max(d[1][0] + a[2][1], d[1][1] + a[2][1]);
	d[2][2] = d[1][1] + a[2][2]

	d[i][j] = max(d[i - 1][j - 1] + a[i][j], d[i - 1][j] + a[i][j])
	
	
	*/


	return 0;
}