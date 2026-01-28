#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	vector<int> qs(T);
	int MAXN = 0;
	for (int i = 0; i < T; i++) {
		cin >> qs[i];
		MAXN = max(MAXN, qs[i]);
	}

	vector<long long> g(MAXN + 1, 0);
	for (int d = 1; d <= MAXN; d++) {
		for (int m = d; m <= MAXN; m += d) {
			g[m] += d;
		}
	}

	vector<long long> F(MAXN + 1, 0);
	for (int n = 1; n <= MAXN; n++) {
		F[n] = F[n - 1] + g[n];
	}

	for (int i = 0; i < T; i++) {
		cout << F[qs[i]] << '\n';
	}

	return 0;
}
