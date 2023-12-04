#include <iostream>

using namespace std;

int N = 3;
int arr[3];


bool promising(int k, int i){
	bool flag = true;
	
	int j = 0;
	while(j < k && flag){
		if(i == arr[j])
			flag = false;
		j++;
	}
	
	return flag;
}
void perm(int k){
	
	if(k == N){
		for(int i = 0; i < N; i++)
			cout << arr[i] << ' ';
			cout << '\n';
			return;
	}
	
	for(int i = 1; i <= N; i++){
		if(promising(k, i)){
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