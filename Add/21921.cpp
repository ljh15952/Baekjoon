#include <iostream>
#include <algorithm>

using namespace std;

int N, X;
long long arr[250001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int l = 0, r = 1;
	int ans = 0, ct = 0;
	for (r = 0; r < X; r++) {
		ct += arr[r];
	}
	ans = ct;
	r--;
	int ct2 = 1;

	while (r < N) {

		ct -= arr[l++];
		ct += arr[++r];

		if (ans == ct) {
			ct2++;
		}
		else if (ct > ans) {
			ct2 = 1;
			ans = ct;
		}
	}

	if (ans == 0) {
		cout << "SAD" << "\n";
	}
	else {
		cout << ans << "\n" << ct2 << "\n";
	}

	return 0;
}
