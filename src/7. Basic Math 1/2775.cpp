#include <iostream>

using namespace std;

int main(){
	cin.tie(0);
	/*
	
	4층
	3층 1 5 15 35 70...
	2층 1 4 10 20 35...
	1층 1 3 6 10 15 21 28...
	0층 1 2 3 4 5 6 7 8 9 10...
	*/
	// 규칙
	//arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
	
	
	int t;
	cin >> t;
	
	for(int z = 0 ; z < t; ++z){
		int k,n;
		
		cin >> k >> n;
		int arr[k+1][n] = {0,};


		for(int i = 0; i <= k; i++){
			arr[i][0] = 1;
		}
		for(int i = 0; i < n; i++){
			arr[0][i] = i + 1;
		}

		for(int i = 1; i <= k; i++){
			for(int j = 1; j < n; j++){
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			}
		}

		cout << arr[k][n-1] << endl;
	}
	
	
	// for(int i = 0; i <= k; i++){
	// 	for(int j = 0; j < n; j++){
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	
	return 0;
}