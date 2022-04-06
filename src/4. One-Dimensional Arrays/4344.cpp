#include <iostream>

using namespace std;

int main(){
	int n;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		
		int arr[a] = {0,};
		int sum = 0;
		for(int j = 0; j < a; j++){
			int num;
			cin >> num;
			arr[j] = num;
			sum += num;
		}
		int avg = sum / a;
		int upScore = 0;
		for(int j = 0; j < a; j++){
			if(arr[j] > avg){
				upScore++;
			}
		}
		float per = upScore / (float)a * 100;
	
		printf("%.3f%%\n",per);
	}
	
	return 0;
}