#include <iostream>

using namespace std;

// 길이가 0일때 0원 1일때 2원 3일때 5원 4일 때 9원 5일때 10원
int arr[5] = {0, 2, 5, 9, 10};
int maxSell[5];

int cutRod(int i){
	
	for(int j = 1; j <= i; j++){
		
		int maxVal = 0;
		for(int k = 1; k <= j; k++)
			maxVal = max(maxVal, arr[k] + maxSell[j - k]);
		maxSell[j] = maxVal;
	}
	
	return maxSell[i];
}


int main(){
	
	cout << cutRod(4) << endl;
	
	return 0;
}