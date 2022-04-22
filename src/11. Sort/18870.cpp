#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	int n;
	
	cin >> n;
	
	vector<int> v;
	vector<int> arr;
	int num;
	for(int i = 0; i < n; i++){
		scanf("%d",&num);
		v.push_back(num);
		arr.push_back(num);
	}
	
	sort(arr.begin(),arr.end());
	arr.erase(unique(arr.begin(),arr.end()),arr.end());
	
	for(int i = 0; i < n; i++){
		printf("%d ",lower_bound(arr.begin(),arr.end(),v[i]) - arr.begin());
	}
	
	return 0;
}