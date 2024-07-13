#include <bits/stdc++.h>

using namespace std;

int T;

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	for (int t = 0; t < T; t++) {
		int n, m;
		int a[20005], b[20005];

		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}

		sort(a, a + n);
		sort(b, b + m);

		int cnt = 0;

		for (int i = 0; i < n; i++) {

			for (int j = 0; j < m; j++) {

				if (a[i] > b[j]) {
					cnt++;
				}

			}

		}

		cout << cnt << '\n';
	}


	return 0;
}