#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int arr[2000001] = {};
	int a;
	for(int i = 0; i < n; ++i){
		cin >> a;
		arr[a] = 1;
	}
	
	int x;
	cin >> x;
	
	int ans = 0;
	for(int i = 1; i <= 2000001; ++i){
		if(x - i <= 0) continue; 
		if(i == x - i) continue;
		if(arr[i] != 1	|| arr[x-i] != 1) continue;
	
		arr[i] = 0;
		ans++;
	}
	
	cout << ans << '\n';
	
	return 0;
}