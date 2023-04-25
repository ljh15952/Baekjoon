#include <bits/stdc++.h>

using namespace std;

int A, K, cnt;
int arr[500000];
int tmp[500000];
int ans;

void merge_sort(int left, int right){
	if(left < right){
		int mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		
		if(cnt >= K) return;
		
		int i = left;
		int j = mid + 1;
		int t = left;
		while(i <= mid && j <= right){
			if(arr[i] <= arr[j])
				tmp[t++] = arr[i++];
			else
				tmp[t++] = arr[j++];
		}
		while(i <= mid)
			tmp[t++] = arr[i++];
		while(j <= right)
			tmp[t++] = arr[j++];

		for(i = left; i <= right; ++i){
			arr[i] = tmp[i];
			if(++cnt == K){
				ans = arr[i];
				break;
			}
		}
	}
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> A >> K;	
	
	for(int i = 0; i < A; ++i){
		cin >> arr[i];
	}
	
	merge_sort(0, A-1);
	
	if(cnt < K) cout << -1 << '\n';
	else cout << ans << '\n';
	
	return 0;
}

/*
병합 정렬
N개의 서로 다른 양의 정수가 저장된 배열 A
병합 정렬로 배열 A를 오름차순 정렬할 경우 
K번째 저장되는 수를 구해라


*/