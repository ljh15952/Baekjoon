#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long N;
	cin >> N;

	long long ans = 0;
	for (long long d = 1; d <= N; d++) {
		ans += d * (N / d);
	}

	cout << ans << '\n';

	return 0;
}
