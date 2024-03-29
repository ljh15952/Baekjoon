#include <bits/stdc++.h>

using namespace std;

int N,M;
// N행 M열
int ans = 0;
int cow = 1;

void func(int n, int m){
	if(n % 2 == 0 || m % 2 == 0) return;
	
	ans += cow;
	cow *= 4;
	func(n/2,m/2);
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	func(N, M);
	
	cout << ans << '\n';
		
	return 0;
}

/*
N,M이 1일 때 소를 놓을 수 있다.
N,M이 


*/

/*
농부 존은 대칭, 균형을 좋아한다. 그리고 
현재 그의 소들을 정리한다.
그의 들판 위에서 파티션으로 NxM의 격자 10억x10억? 너무 큰데

대칭을 보존하기 위해서 농부 존은 다음 방법으로 소를 배치한다.
그는 소를 놓는다. 가장 가운데의 격자사각 들판의
만약 남아있는 격자가 없으면 그만 둔다.
그리고 그는 들판을 나눈다 4개의 같은 사이즈의 작은 들판으로

분리된다. 열과 행으로 소의 가운데

그리고 정리한다. 소들을 각각의 전의 들판으로
그는 반복한다 나누는 것을 제일 작은 들판이 더 이상 가운데 사각이
존재하지 않거나 나누어 지지 않을 때 까지

NxM = 5

. . | . .
. . | . .
- - C - -
. . | . .
. . | . .
-> 한개밖에 못 놓는데용

*/