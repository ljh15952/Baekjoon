#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	long long sum = 0;
	for (int i = 0; i < K; i++)
		sum += arr[i];

	long long ans = sum;

	for (int i = K; i < N; i++) {
		sum += arr[i];
		sum -= arr[i - K];
		ans = max(ans, sum);
	}

	cout << ans << "\n";

	return 0;
}

/*

*/
