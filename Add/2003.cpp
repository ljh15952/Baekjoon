#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	long long M;
	cin >> N >> M;

	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];

	int l = 0, r = 0;
	long long sum = 0;
	long long cnt = 0;

	while (true) {
		if (sum >= M) {
			if (sum == M) cnt++;
			sum -= a[l++];
		} else {
			if (r == N) break;
			sum += a[r++];
		}
	}

	cout << cnt << "\n";
	return 0;
}
