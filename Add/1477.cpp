#include <iostream>
#include <algorithm>

using namespace std;

int N, M, L;
int arr[200];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> L;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	arr[N] = 0;
	arr[N + 1] = L;

	sort(arr, arr + N + 2);


	int l = 1;
	int r = L - 1;
	int ans = 0;

	while (l <= r) {
		int mid = (l + r) / 2;
		int need = 0;

		for (int i = 1; i < N + 2; i++) {
			int gap = arr[i] - arr[i - 1];
			need += (gap - 1) / mid;
		}

		if (need > M) {
			l = mid + 1;
		}
		else {
			ans = mid;
			r = mid - 1;
		}
	}

	cout << ans << "\n";

	return 0;
}
