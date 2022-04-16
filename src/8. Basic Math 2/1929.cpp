#include <iostream>
#include <vector>
using namespace std;

int main(){
	int M,N;
	
	scanf("%d %d",&M,&N);
	
	int arr[1000001] = {0,};
	
	arr[1] = 1;
	
	
	
	//2 3 5 7 11 13
	
	for(int i = 2; i <= N; ++i){
		for(int j = 2; j * i <= N; ++j){
			arr[i*j] = 1;
		}
	}
	
	
	
	for(int i = M; i <= N; i++){
		if(arr[i] == 0)
			cout << i << endl;
	}
	
	return 0;
}