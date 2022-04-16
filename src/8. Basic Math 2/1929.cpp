#include <iostream>
#include <vector>
using namespace std;

int main(){
	int M,N;
	
	cin >> M >> N;
	
	int arr[1000000] = {0,};
	
	arr[0] = 1;
	
	
	//2 3 5 7 11 13
	
	for(int i = 2; i < N; i++){
		
	}
	
	
	
	for(int i = M; i <= N; i++){
		if(arr[i] == 0)
			cout << i << endl;
	}
	
	return 0;
}