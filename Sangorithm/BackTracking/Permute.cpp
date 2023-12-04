#include <iostream>

using namespace std;

int N = 3;
int arr[3];


bool promising(int k, int i){

	cout << "Call pro K is " << k  << " i is " << i; 

	for(int j = 0; j < k; j++){
		if(i == arr[j]){
			cout << " false!\n";
			return false; 
		}
	}
	cout << " true!\n";
	return true;
}
void perm(int k){
	
	cout << "Call perm K is " << k << endl; 
	
	if(k == N){
		for(int i = 0; i < N; i++)
			cout << arr[i] << ' ';
			cout << '\n';
			return;
	}
	
	for(int i = 1; i <= N; i++){
		if(promising(k, i)){
			cout << "Add " << i << " to arr[" << k << "]\n";
			arr[k] = i;
			perm(k+1);
		}
	}
}

int main(){
	
	perm(0);
	
	return 0;
}

/*

1,2,3,,N 의 모든 순열을 생성한 후 출력

*/