#include <iostream>

using namespace std;

int getNum(int i){
	int sum = i;
	while(i != 0){
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

int main(){
	
	bool arr[10001] = {false,};
	
	for(int i = 1; i < 10001; i++){
		int num = getNum(i);
		if(num <= 10001)
			arr[num] = true;
	}
	
	for(int i = 1; i < 10001; i++){
		if(arr[i] == false)
			cout << i << endl;
	}

	
	return 0;
}