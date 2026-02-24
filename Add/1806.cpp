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

	int l = 0, r = 0;
	long long sum = 0;
	int ans = 100001;
	while (r <= N) {

		if (sum < M) {
			sum += arr[r++];
		}
		else if (sum >= M) {
			ans = min(ans, r - l);
			sum -= arr[l++];
		}
	}

	if (ans == 100001)
		ans = 0;
	cout << ans << endl;

	return 0;
}

/*
*/
