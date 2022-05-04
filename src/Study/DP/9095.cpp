#include <iostream>

using namespace std;

int ct = 0;

/*
void add(int sum, int goal){
	if(sum > goal){
		return;
	}else if(sum == goal){
		ct++;
	}else{
		for(int i = 1; i <= 3; ++i){
			add(sum + i, goal);
		}
	}
}
*/

int main(){
	
	int n;
	
	cin >> n;
	
	int num;
	
	// for(int i = 0; i < n; ++i){
	// 	cin >> num;
	// 	add(0,num);
	// 	cout << ct << endl;
	// 	ct = 0;
	// }
	
	int dp[11] = {0,};
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	for(int i = 0; i < n; ++i){
		cin >> num;
		
		for(int j = 4; j <= num; ++j){
			dp[j] = dp[j-1] + dp[j-2] + dp[j - 3];
		}
		cout << dp[num];
	}
	
	return 0;
}