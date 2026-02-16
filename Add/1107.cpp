
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int M;
vector<bool> broken(10, false);

int getDigits(int x) {
	if (x == 0) return broken[0] ? -1 : 1;
	int cnt = 0;
	while (x > 0) {
		int d = x % 10;
		if (broken[d]) return -1;
		cnt++;
		x /= 10;
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		broken[x] = true;
	}

	int ans = abs(N - 100);

	for (int i = 0; i <= 500000*2; i++) {
		int len = getDigits(i);
		if (len == -1) continue;
		ans = min(ans, len + abs(N - i));
	}

	cout << ans << endl;

	return 0;
}
