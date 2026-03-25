#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	int r = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		r += arr[i];
	}

	int l = *max_element(arr, arr + N);
	int ans = r;

	while (l <= r) {
		int mid = (l + r) / 2;
		
		int cnt = 1;
		long long int sum = 0;

		for (int i = 0; i < N; i++){
			if (sum + arr[i] > mid) {
				cnt++;
				sum = arr[i];
			}
			else {
				sum += arr[i];
			}
		}

		if (cnt <= M) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans << endl;

	return 0;
}
