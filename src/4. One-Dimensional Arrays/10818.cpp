#include <iostream>

using namespace std;

int main(){
	cin.tie(NULL);
	int n;
	
	cin >> n;
	
	int min = 9999999;
	int max = -9999999;
	for(int i = 0; i < n; i++){
		int num;
		
		cin >> num;
		
		if(num > max)
			max = num;
		if(num < min)
			min = num;
	}
	
	cout << min << " " << max << endl;
	
	return 0;
}