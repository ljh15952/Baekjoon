#include <bits/stdc++.h>

using namespace std;

int n;
long long arr[100005];


int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	long long int max = 1;
	long long int ans = arr[0];
	long long int cnt = 1;

	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1])
			cnt++;
		else
			cnt = 1;

		if (max < cnt) {
			max = cnt;
			ans = arr[i];
		}
	}

	cout << ans << '\n';
	
	return 0;
}