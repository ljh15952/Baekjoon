#include <iostream>

using namespace std;

int main(){
	
	int arr[42] = {0,};
	
	int score = 0;
	
	for(int i = 0; i < 10; i++){
		int n;
		cin >> n;
		int remainder = n % 42;
		
		arr[remainder]++;
	}
	
	for(int i = 0; i < 42; i++){
		if(arr[i] > 0)
			score++;
	}
	
	cout << score << endl;
	
	return 0;
}