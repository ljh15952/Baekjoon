#include <iostream>

using namespace std;

int main() {
	int n;
	int i;
	int arr[10001] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		arr[temp]++;
	}
	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < arr[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;
}
