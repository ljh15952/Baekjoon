#include <iostream>

using namespace std;

long long N, B, C;
long long A[1000000];
long long ans = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (long long int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;
	

	for (int i = 0; i < N; i++) {
		ans++;
		
		long long remain = A[i] -= B;
		if (A[i] > 0) {
			ans += (remain + C - 1) / C;
		}
	}

	cout << ans << endl;

	return 0;
}
