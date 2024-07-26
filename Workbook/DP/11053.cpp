#include <bits/stdc++.h>

using namespace std;

int n;
int a[1005];
int d[1005];

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int num = 0;
	for (int i = 1; i <= n; i++) {
		int m = 0;
		for (int j = 1; j < i; j++) {
			if (m < d[j] && a[j] < a[i])
				m = d[j];
		}
		d[i] = m + 1;
		num = max(d[i], num);
	}

	cout << num << '\n';

	return 0;
}