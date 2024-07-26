#include <bits/stdc++.h>

using namespace std;

int n;
int a[1005];
int d[1005];
int w[1005];

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (d[i] < d[j] + 1 && a[j] < a[i]) {
				d[i] = d[j] + 1;
				w[i] = j;
			}
		}
	}

	int maxi = 1, maxd = d[1];
	for (int i = 2; i <= n; i++) {
		if (maxd < d[i]) {
			maxi = i;
			maxd = d[i];
		}
	}

	deque<int> ans;
	int cur = maxi;
	while (cur) {
		ans.push_front(a[cur]);
		cur = w[cur];
	}

	cout << ans.size() << '\n';
	for (auto v : ans) cout << v << ' ';

	return 0;
}