#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[10000];
long long M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> M;

	int max_num = *max_element(arr, arr + N);

	int l = 0, r = max_num;
	int ans = 0;

	while (l <= r) {
		int mid = (l + r) / 2;

		long long sum = 0;
		for (int i = 0; i < N; i++) {
			sum += (arr[i] > mid ? mid : arr[i]);
		}

		if (sum <= M) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << ans << endl;

	return 0;
}
