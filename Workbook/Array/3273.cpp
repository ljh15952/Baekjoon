#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int arr[n] = {};
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	
	int x;
	cin >> x;
	
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(arr[i] + arr[x - i] == x) ans++;
	}
	
	cout << ans << '\n';
	
	return 0;
}