#include <iostream>

using namespace std;

int main(){
	
	int arr[123456*2] = {0,};
	arr[1] = 1;
	
	for(int i = 2; i <= 123456*2; ++i){
		for(int j = 2; j * i <= 123456*2; ++j){
			arr[i*j] = 1;
		}
	}
	
	int n;
	scanf("%d",&n);
	int sum = 0;
	while(n != 0){
		for(int i = n+1; i <= n*2; i++){
			if(arr[i] == 0){
				sum++;
			}
		}
		printf("%d\n",sum);
		scanf("%d",&n);
		sum = 0;
	}
	return 0;
}