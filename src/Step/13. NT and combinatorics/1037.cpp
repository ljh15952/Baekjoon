#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	int n;
	
	cin >> n;
	
	vector<int> arr;
	int a;
	
	for(int i = 0; i < n; ++i){
		cin >> a;
		arr.push_back(a);
	}
	
	sort(arr.begin(),arr.end());

	cout << arr.front() * arr.back() << endl;
	
	return 0;
}