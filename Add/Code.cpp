#include <bits/stdc++.h>

using namespace std;

int main()
{
	
	ios::sync_with_stdio(0); cin.tie(0);

	int arr[10] = { 3, 2, 7, 116, 62, 235, 1, 23, 55, 77 };
	int n = 10;

	for (int i = n - 1; i > 0; i--) {

		int maxIdx = 0;

		for (int j = 1; j <= i; j++) {
			if (arr[maxIdx] < arr[j]) {
				maxIdx = j;
			}
		}

		swap(arr[i], arr[maxIdx]);
	}

	// Short
	//for (int i = n - 1; i > 0; i--) {
	//	swap(*max_element(arr, arr + i + 1), arr[i]);
	//}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}
