#include <iostream>
#include <algorithm>

using namespace std;

int N, C;
long long arr[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> C;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int l = 1;
	int r = arr[N - 1] - arr[0];
	int ans = 0;

	while (l <= r) {
		int mid = (l + r) / 2;

		int cnt = 1;
		int last = arr[0];

		for (int i = 1; i < N; i++) {
			if (arr[i] - last >= mid) {
				cnt++;
				last = arr[i];
			}
		}

		if (cnt >= C) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	
	cout << ans << "\n";

	return 0;
}
