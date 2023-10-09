#include <iostream>

using namespace std;

int N;
int arr[15];
int oper[4];

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	for(int i = 0; i < 4; i++){
		cin >> oper[i];
	}
	
	for(int i = 0; i < N; i++){
		cout << arr[i] << '\n';
	}
	
	for(int i = 0; i < 4; i++){
		cout << oper[i] << '\n';
	}
	
	
	return 0;
}

/*
연산자 끼워넣기

6개의 수
연산자 + 2, - 1, x 1, / 1 5개
가능한 경우의 수 60


*/