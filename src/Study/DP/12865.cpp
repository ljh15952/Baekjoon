#include <iostream>
#include <vector>
using namespace std;

int dp[101][100001];
int w[101];
int v[101];

// 점화식 max(dp[i-1][j],dp[i-1][j-w[i]])

int main(){
	
	int n, k;
	cin >> n >> k;
	
		
	for(int i = 1; i <= n; ++i){
		cin >> w[i] >> v[i];
	}
	
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= k; ++j){
			if(j - w[i] >= 0)
				dp[i][j] = max(dp[i-1][j],dp[i-1][j - w[i]] + v[i]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	
	cout << dp[n][k] << endl;
	
	return 0;
}
// n = 4 물건 수
// k = 7 가방 크기
// w weight array
// 0 1 2 3 4 
// - 6 4 3 5
// v value array
// 0 1  2 3 4
// - 13 8 6 12

// dp[101][1000001]
//     0   1   2   3   4   5   6   7   8   9   10  11  12
// 0   0   0   0   0   0   0   0   0   0   0   0   0   0
// 1   0   0   0   0   0   0   13  13
// 2   0
// 3   0
// 4   0
// 5   0
// .
// .
// .
// 101 0

// i 1->n
//     j 1->j
//         만약 j 랑 w[i]를 뺀 것이 0보다 크거나 같으면
//             dp[i][j]번째 배열은 dp[i-1][j]랑 dp[i-1][j - w[i]] + v[i]) 중에 큰 것
//         아니면
//             dp[i][j] 번째 배열은 dp[i-1][j]

// for(int i = 1; i <= n; i++){
//     for(int j = 1; j <= k; j++){
//         if(j - w[i] >= 0)
//             dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]] + v[i]);
//         else
//             dp[i][j] = dp[i-1][j];
//     }
// }