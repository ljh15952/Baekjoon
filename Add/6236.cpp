#include <iostream>
#include <algorithm>
#include "ConsoleApplication1.h"

using namespace std;

int N, M;
int arr[100005];
int sum = 0;

bool canWithdraw(int K) {
	int cnt = 1;
	int remain = K;

	for (int i = 0; i < N; i++) {
		if (arr[i] > K) return false;

		if (remain < arr[i]) {
			cnt++;
			remain = K;
		}
		remain -= arr[i];
	}
	return cnt <= M;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	int l = *max_element(arr, arr + N);;
	int r = sum;
	int ans = sum;

	while (l <= r) {
		int mid = (l + r) / 2;

		if (canWithdraw(mid)) {
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
