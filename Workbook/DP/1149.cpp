#include <bits/stdc++.h>

using namespace std;

int n;

int r[1005];
int g[1005];
int b[1005];

int d[1005][3];
int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;



	for (int i = 1; i <= n; i++) {
		cin >> r[i] >> g[i] >> b[i];
	}
	
	d[1][0] = r[1];
	d[1][1] = g[1];
	d[1][2] = b[1];

	for (int i = 2; i <= n; i++) {
		d[i][0] = min(r[i] + d[i - 1][1], r[i] + d[i - 1][2]);
		d[i][1] = min(g[i] + d[i - 1][0], g[i] + d[i - 1][2]);
		d[i][2] = min(b[i] + d[i - 1][0], b[i] + d[i - 1][1]);
	}

	cout << min(d[n][0], min(d[n][1], d[n][2])) << '\n';

	return 0;
}

/*

앞에 집에서 r을 선택 했을 경우의 최소값
앞에 집에서 g을 선택 했을 경우의 최소값
앞에 집에서 b을 선택 했을 경우의 최소값

d[1][0] = r[0]
d[1][1] = g[0]
d[1][2] = b[0]

d[2][0] = min(r[2] + d[1][1], r[2] + d[1][2])
d[2][1] = min(g[2] + d[1][0], g[2] + d[1][2])
d[2][2] = min(b[2] + d[1][0], b[2] + d[1][1])

*/