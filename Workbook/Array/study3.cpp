#include <bits/stdc++.h>

using namespace std;

int func2(int arr[], int N){
	int tmp[] = {};
	for(auto it : arr) tmp[it++];
	for(auto it : arr){
		if(tmp[100-it] == 1)
			return 1;
	}
	return 0;
}

int main(){
	
	cout << func2({1,52,48}, 3) << '\n'; // 1
	cout << func2({50, 42}, 2) << '\n'; // 0
	cout << func2({4, 13, 63, 87}, 4) << '\n'; // 1
	
	return 0;
}