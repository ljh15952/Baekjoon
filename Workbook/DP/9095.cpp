#include <bits/stdc++.h>

using namespace std;

int arr[11];
int t, n;

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> t;


	for (int j = 0; j < t; j++) {
		cin >> n;

		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 4;

		for (int i = 4; i <= n; i++) {
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
		}

		cout << arr[n] << '\n';
	}

	return 0;
}