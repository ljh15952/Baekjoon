#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int vv;

vector<int> v = { 0 };
int d[42];

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	
	while (m--) {
		cin >> vv;
		v.push_back(vv);
	}
	v.push_back(n + 1);

	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 2] + d[i - 1];
	}

	int ans = 1;
	for (int i = 1; i < v.size(); i++) ans *= d[v[i] - v[i - 1] - 1];
	cout << ans;

	return 0;
}