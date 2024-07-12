#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int n;
int c;

vector<pair<int, int>> arr; // num, cnt

bool cmp(const pair<int, int>& a,const pair<int, int>& b) {
	return a.X > b.X;
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		bool flag = false;

		for (auto& a : arr) {
			if (a.Y == x) {
				flag = true;
				a.X++;
				break;
			}
		}

		if (!flag)
			arr.push_back({ x, 1 });
	}

	stable_sort(arr.begin(), arr.end(), cmp);

	for (auto b : arr)
		while (b.X--)
			cout << b.Y << ' ';
	cout << '\n';

	return 0;
}