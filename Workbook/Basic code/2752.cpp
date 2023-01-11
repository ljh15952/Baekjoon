#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	vector<int> arr;
	int a;
	for(int i = 0; i < 3; ++i){
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(),arr.end());
	for(auto n : arr) cout << n << ' ';
}