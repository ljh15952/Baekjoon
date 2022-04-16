#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	
	// int T;
	
	// scanf("%d",&T);
	
	int arr[10001] = {0,};
	arr[1] = 1;
	
	vector<int> sosu;
		
	for(int i = 2; i <= 10000; ++i){
		for(int j = 2; j * i <= 10000; ++j){
			arr[i*j] = 1;
		}
	}
	
	for(int i = 2; i <= 100; ++i){
		if(arr[i] == 0){
		 	sosu.push_back(i);
		}
	}
	
	int n;
	
	cin >> n;
	
	int sum = 0;
	
	int min = 999999;
	int a,b;	
	
	//TODO
	/*
	만약 가능한 n의 골드바흐 파티션이 여러 가지인 경우에는 두 소수의 차이가 가장 작은 것을 출력한다.
	*/
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(n == sosu[i]+sosu[j]){
				//cout << sosu[i] << "+" << sosu[j] << "= " << n << endl;
				//cout << sosu[i] << " " << sosu[j] << endl;
				if(min > abs(sosu[i] - sosu[j])){
					min = sosu[i] - sosu[j];
					a = sosu[i];
					b = sosu[j];
				}
			}
		}
	}
	
	cout << a << " " << b << endl;
	
	return 0;
}