#include <iostream>
#include <vector>

using namespace std;

int N;
int x, y, d, g;

bool mp[101][101] = {};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;

		vector<int> dirs;
		dirs.push_back(d);

		for (int gen = 0; gen < g; gen++) {
			for (int k = (int)dirs.size() - 1; k >= 0; k--) {
				dirs.push_back((dirs[k] + 1) % 4);
			}
		}

		mp[y][x] = true;
		for (int dir : dirs) {
			x += dx[dir];
			y += dy[dir];
			mp[y][x] = true;
		}
	}

	int ans = 0;
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (mp[y][x] && mp[y][x + 1] && mp[y + 1][x] && mp[y + 1][x + 1]) {
				ans++;
			}
		}
	}
	cout << ans << "\n";

	return 0;
}
