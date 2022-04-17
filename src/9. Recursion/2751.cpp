#include <iostream>

using namespace std;

int* arr;
int* arr2;

void merge(int left, int right) {
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
			arr2[k++] = arr[i++];
		else
			arr2[k++] = arr[j++];
	}
	
	int temp = i > mid ? j : i;
	
	while (k <= right) 
		arr2[k++] = arr[temp++];
	for (int i = left; i <= right; i++)
		arr[i] = arr2[i];
}

void partition(int left, int right) {
	int mid;
	
	if (left < right) {
		mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1,right);
		merge(left, right);
	}
}
int main() {
	int n;
	cin >> n;
	arr = new int[n];
	arr2 = new int[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	partition(0,n-1);
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
}