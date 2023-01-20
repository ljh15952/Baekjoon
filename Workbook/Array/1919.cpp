#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int arr[27] = {};
	
	string s;
	cin >> s;
	for(int it : s){
		arr[it - 'a']++;
	}
	cin >> s;
	for(int it : s){
		arr[it - 'a']--;
	}
	
	int sum = 0;
	for(auto it : arr){
		sum += abs(it);
	}
	
	cout << sum << '\n';
	
	return 0;
}