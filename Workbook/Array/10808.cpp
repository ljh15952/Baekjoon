#include <bits/stdc++.h>

using namespace std;

int arr[26];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	string s;
	cin >> s;
	
	for(int i = 0; i < s.size(); ++i){
		arr[s[i] - 'a']++;
	}
	
	for(auto it : arr) cout << it << ' ';
	
	return 0;
}