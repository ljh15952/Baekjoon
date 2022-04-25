#include <iostream>

using namespace std;

#define mod 10007
#define MAX 1001

int dp[MAX][MAX];

void f(int a,int b){
	for(int i = 0; i <= a; i++){
		for(int j = 0; j <= b; j++){
			if(i == j || j == 0){
				dp[i][j] = 1;
			}else{
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
			}
		}
	}
}

int main(){

	int n,k;
	cin >> n >> k;
	f(n,k);
	cout << dp[n][k] << endl;
	
	return 0;
}