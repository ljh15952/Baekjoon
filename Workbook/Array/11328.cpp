#include <bits/stdc++.h>

using namespace std;

bool checked(int arr[], string s){
	for(auto it : s){
		if(arr[it - 'a'] <= 0){
			return false;
		} 
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N;
	cin >> N;
	while(N--){
		int alpha[26] = {};
		string s1, s2;
		cin >> s1 >> s2;
		
		for(auto it : s1) alpha[it - 'a']++;
		for(auto it : s2) alpha[it - 'a']--;
		
		bool flag = true;
		for(auto it : alpha){
			if(it != 0) flag = false;
		}
		
		if(flag) cout << "Possible" << '\n';
		else cout << "Impossible" << '\n';
		
	}
		
}