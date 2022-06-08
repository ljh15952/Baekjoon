#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	int n,k;
	scanf("%d %d",&n,&k);
	
	vector<int> vec;
	int a;
	for(int i = 0; i < n; ++i){
		scanf("%d",&a);
		vec.push_back(a);
	}
	
	sort(vec.begin(),vec.end());
	
// 	for(auto it : vec){
// 		cout << it << endl;
// 	}
	
	cout << vec[k-1] << '\n';
	
	return 0;
}