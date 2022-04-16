#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSosu(int n){
	if(n == 1)
		return false;
	for(int i = 2; i < n; i++){
		if(n % i == 0)
			return false;
	}
	return true;
}


int main(){
	
	int M,N;
	
	cin >> M >> N;
	
	vector<int> arr;
	
	for(int i = M; i <= N; i++){
		if(isSosu(i)){
			arr.push_back(i);
		}
	}
	
	if(arr.size() == 0){
		cout << "-1" << endl;
		return 0;
	}
	
	int sum = 0;
	
	for(int i : arr){
		sum += i;
	}
	
	cout << sum << endl << *min_element(arr.begin(),arr.end()) << endl;
	
	return 0;
}