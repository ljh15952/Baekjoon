#include <iostream>
#include <algorithm>
using namespace std;

long long N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	
	long long ans = 0;
	long long start = 1;
	int len = 1;

	while (start <= N) {
		long long end = min(N, start * 10 - 1);
		ans += (end - start + 1) * len;

		start *= 10;
		len++;
	}

	cout << ans << "\n";

	return 0;
}
