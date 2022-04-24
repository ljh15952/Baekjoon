#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a,int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b,a%b);
	}
}

int main(){
	
	int n;
	cin >> n;
	
	int num;
	vector<int> arr;
	
	for(int i = 0; i < n; ++i){
		scanf("%d",&num);
		arr.push_back(num);
	}
	
	sort(arr.begin(),arr.end());
	
	int gcdVal = arr[1] - arr[0];
	
	for(int i = 2; i < n; ++i){
		gcdVal = gcd(gcdVal,arr[i] - arr[i - 1]);
	}
	vector<int> ans;
	for(int i = 2; i * i <= gcdVal; ++i){
		if(gcdVal % i == 0){
			ans.push_back(i);
			ans.push_back(gcdVal / i);
		}
	}
	
	ans.push_back(gcdVal);
	
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	
	for(int i : ans){
		cout << i << " ";
	}
	
	return 0;
}