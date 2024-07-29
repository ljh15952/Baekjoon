#include <bits/stdc++.h>

using namespace std;

int n;
int k;

int c[105];
int d[10005];

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	d[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = c[i]; j <= k; j++) {
			d[j] += d[j - c[i]];
		}
	} 

	for (int i = 1; i <= k; i++) 
		cout << i << ':' << d[i] << '\n';

	//cout << d[k] << '\n';

	return 0;
}