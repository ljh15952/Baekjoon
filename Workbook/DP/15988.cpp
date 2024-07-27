#include <bits/stdc++.h>

using namespace std;

int n;
int t;
long long int d[1000005];

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;

		d[1] = 1;
		d[2] = 2;
		d[3] = 4;
		long long int dev = 1000000009;
		for (int i = 4; i <= n; i++) {
			d[i] = (d[i - 1] + d[i - 2] + d[i - 3]) % 1000000009;
		}

		cout << d[n] << '\n';
	}

	

	return 0;
}
