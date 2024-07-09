#include <bits/stdc++.h>

using namespace std;

int arr[2000005];
int n;

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[1000000 + a]++;
	}

	for (int i = 0; i <= 2000000; i++) {
		/*
		if (arr[i] > 0) {
			for (int j = 0; j < arr[i]; j++) {
				cout << i - 1000000 << '\n';
			}
		}
		*/
		// answer code
		while (arr[i]--) {
			cout << i - 1000000 << '\n';
		}
	}

	return 0;
}