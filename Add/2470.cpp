#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	//

	//
	sort(arr, arr + N);

	int l = 0, r = N - 1;
	long long bestAbs = llabs(arr[l] + arr[r]);
	long long ans1 = arr[l], ans2 = arr[r];

	while (l < r) {
		long long s = arr[l] + arr[r];
		long long ab = llabs(s);
	
		if (ab < bestAbs) {
			bestAbs = ab;
			ans1 = arr[l];
			ans2 = arr[r];
			if (bestAbs == 0) break;
		}

		if (s > 0) r--;
		else l++;
	}

	cout << ans1 << ' ' << ans2 << "\n";

	return 0;
}
