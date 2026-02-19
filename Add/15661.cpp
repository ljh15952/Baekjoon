#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int S[20][20];
int W[20][20];
long long ans = (1LL << 60);

long long addScore(int p, int mask) {
	long long add = 0;
	for (int j = 0; j < N; j++) {
		if (mask & (1 << j)) {
			int a = min(p, j), b = max(p, j);
			add += W[a][b];
		}
	}
	return add;
}

void dfs(int idx, int maskA, int maskB, long long scoreA, long long scoreB) {
	if (idx == N) {
		if (maskA == 0 || maskB == 0) return;
		ans = min(ans, llabs(scoreA - scoreB));
		return;
	}
	{
		long long inc = addScore(idx, maskA);
		dfs(idx + 1, maskA | (1 << idx), maskB, scoreA + inc, scoreB);
	}
	
	{
		long long inc = addScore(idx, maskB);
		dfs(idx + 1, maskA, maskB | (1 << idx), scoreA, scoreB + inc);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			W[i][j] = S[i][j] + S[j][i];
		}
	}

	int maskA = (1 << 0);
	int maskB = 0;
	dfs(1, maskA, maskB, 0, 0);

	cout << ans << '\n';


	return 0;
}
