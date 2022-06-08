#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	int n,k;
	
	cin >> n >> k;
	
	vector<int> vec;
	int a;
	for(int i = 0; i < n; ++i){
		cin >> a;
		vec.push_back(a);
	}
	
	sort(vec.begin(),vec.end());
	
// 	for(auto it : vec){
// 		cout << it << endl;
// 	}
	
	cout << vec[k-1] << endl;
	
	return 0;
}