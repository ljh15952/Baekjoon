#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
inr arr[100001];

int search(int n){
	//TODO 이분탐색
	
}

int main(){
	
	cin >> n;
	
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	
	cin >> m;
		
	for(int i = 0; i < m; ++i){
		int t;
		cin >> t;
		
		cout << search(t) << endl;;
	}
	
	return 0;
}