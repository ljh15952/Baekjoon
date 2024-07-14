#include <bits/stdc++.h>

using namespace std;

int arr[1000005];


int main() {

	ios::sync_with_stdio(0); cin.tie(0);
	

	int x;

	cin >> x;

	arr[1] = 0;

	int a, b, c;
	for (int i = 2; i <= x; i++) {

		if (i % 3 == 0) {
			a = arr[i / 3] + 1;
		}
		else {
			a = 9999;
		}
		
		if (i % 2 == 0) {
			b = arr[i / 2] + 1;
		}
		else {
			b = 9999;
		}
		c = arr[i - 1] + 1;

		arr[i] = min(a, min(b, c));
	}

	cout << arr[x] << '\n';

	return 0;
}