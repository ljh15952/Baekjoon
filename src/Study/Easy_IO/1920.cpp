#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int t;
int arr[100001];

int search(int num){
	//TODO 이분탐색
	int start = 0;
	int end = n - 1;
	
	while(start <= end){
		int mid = (start + end) / 2;
		if(arr[mid] == num)
			return 1;
		else if(num < arr[mid])
			end = mid - 1;
		else 
			start = mid + 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	
	cin >> m;
		
	for(int i = 0; i < m; ++i){
		cin >> t;
		cout << search(t) << "\n";
	}
	
	return 0;
}