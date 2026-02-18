#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int arr[10][10];
int check[10][10];

int ans = -1000000000;

void select(int start, int cnt, int sum) {

	if (cnt == K) {
		ans = max(ans, sum);
		return;
	}

	for (int pos = start; pos < N * M; pos++) {
		int i = pos / M;
		int j = pos % M;

		if (check[i][j]) continue;
		
		bool flag = false;
		for (int d = 0; d < 4; d++) {
			int ny = i + dy[d];
			int nx = j + dx[d];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (check[ny][nx]) { flag = true; break; }
		}
		if (flag) continue;

		check[i][j] = 1;
		select(pos + 1, cnt + 1, sum + arr[i][j]);
		check[i][j] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	select(0, 0, 0);

	cout << ans << '\n';

	return 0;
}
