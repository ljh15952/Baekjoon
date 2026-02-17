#include <iostream>
using namespace std;

long long T, M, N, x, y;

long long gcd(long long a, long long b) {
	while (b) {
		long long t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;

	while (T--) {
		cin >> M >> N >> x >> y;

		long long g = gcd(M, N);
		if ((y - x) % g != 0) {
			cout << -1 << "\n";
			continue;
		}

		long long lcm = (M / g) * N;

		long long k = x;
		while (k <= lcm) {
			if ((k - y) % N == 0) {
				cout << k << "\n";
				break;
			}
			k += M;
		}
		if (k > lcm)
			cout << -1 << "\n";
	}

	return 0;
}

/*

*/
