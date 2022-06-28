#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b){
	if(b == 0)
		return a;
	else
		return GCD(b,a%b);
}

int main(){
	
	int t;
	/*
	
	10 20 30 40
	
	10 1 2 5 10
	20 1 2 4 5 10 20
	30 1 2 3 5 6 10 15 30
	40 1 2 4 5 8 10 20 40
	
	10 20 = 10
	10 30 = 10
	10 40 = 10
	20 30 = 10
	20 40 = 20
	30 40 = 10
	------->70
	
	*/
	
	cin >> t;
	
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		vector<int> arr;
		long long int ans = 0; //답
		for(int j = 0; j < n; ++j){
			int l;
			cin >> l;
			arr.push_back(l);
		}
		for(int j = 0; j < n; ++j){
			for(int k = j+1; k < n; ++k){
				ans += GCD(arr[j],arr[k]);
			}
		}
		cout << ans << endl;
	}
	
	
	
	
	return 0;
}