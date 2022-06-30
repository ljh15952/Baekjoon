#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
	
	int arr[10001] = {0,};
	arr[1] = 1;
	
	for(int i = 6; i <= 1000000; ++i){
		for(int j = 6; j * i <= 1000000; ++j){
			arr[i*j] = 1;
		}
	}
	
	for(int i = 0; i < 100; ++i){
		cout << arr[i] << endl;
	}
	
	return 0;
}