#include <bits/stdc++.h>

using namespace std;


int n;
int arr[1000001];
int tmp[1000001];

void merge(int st, int en) {
	int mid = (st + en) / 2;
	
	int aIdx = st;
	int bIdx = mid;

	for (int i = 0; i < en - st; i++) {
		
		if (aIdx == mid) 
			tmp[st + i] = arr[bIdx++];
		else if (bIdx == en) 
			tmp[st + i] = arr[aIdx++];
		else if (arr[aIdx] < arr[bIdx]) 
			tmp[st + i] = arr[aIdx++];
		else 
			tmp[st + i] = arr[bIdx++];
	}
	
	for (int i = st; i < en; i++) {
		arr[i] = tmp[i];
	}
	
}

void merge_sort(int st, int en) {
	if (st + 1 == en) return;
	int mid = (st + en) / 2;
	merge_sort(st, mid);
	merge_sort(mid, en);
	merge(st, en);
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	merge_sort(0, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';

	return 0;
}