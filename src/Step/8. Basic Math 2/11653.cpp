#include <iostream>
#include <vector>
using namespace std;

int main(){
	
	int n;
	
	cin >> n;
	
	vector<int> arr;
	
	int k = 2;
	
	while(n > 1){
		if(n % k == 0){
			arr.push_back(k);
			n /= k;
		}else{
			k++;
		}
	}
	
	for(int i : arr){
		cout << i << endl;
	}
	
	return 0;
}