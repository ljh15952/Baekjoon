#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long M;
long long arr[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	long long l = 1;
	long long r = arr[N - 1] * M;
	long long ans = r;

	while (l <= r) {
		long long mid = (l + r) / 2;

		long long cnt = 0;

		for (int i = 0; i < N; i++) {
			cnt += mid / arr[i];
			if (cnt >= M) break;
		}

		if (cnt >= M) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans << "\n";

	return 0;
}
