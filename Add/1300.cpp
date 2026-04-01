#include <iostream>
#include <algorithm>

using namespace std;

long long int N, K;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> K;

	long long left = 1;
	long long right = K;   // k번째 수는 k를 넘지 않음
	long long answer = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;

		long long count = 0;
		for (long long i = 1; i <= N; i++) {
			count += min(N, mid / i);
		}

		if (count >= K) {
			answer = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << answer << '\n';

	return 0;
}
