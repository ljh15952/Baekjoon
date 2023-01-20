#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int arr[11] = {};
	
	string N;
	cin >> N;
	
	for(int it : N){
		arr[it - '0']++;
	}
	
	int ans = 0;
	
	for(int i = 0; i < 10; i++){
		if(i == 6 || i == 9) continue;
		ans = max(ans, arr[i]);
	}
	
	ans = max(ans, (arr[6]+arr[9]+1)/2);
  cout << ans;
	
	return 0;
}