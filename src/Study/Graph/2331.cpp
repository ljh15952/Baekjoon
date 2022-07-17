#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int visited[236197];
int p;


void dfs(int k){
	visited[k]++;
	if(visited[k] == 3)
		return;
	int sum = 0;
	while(k){
		sum += (int)pow((k % 10), p);
		k /= 10;
	}
	dfs(sum);
}


int main(){
	
	/*
	다음과 같이 정의된 수열이 있다.
	D[1] = A
	D[n] = D[n-1] 의 각 자리의 숫자를 P번 곱한 수들의 합
	예를 들어
	A = 57, P = 2일 때 수열 D는 [57, 74(5제곱+7제곱=25+49),65,61,37,58,89,145,42,20,4,16,37...]
	그 귀에는 앞서 나온 수들이 반복된다.?57부터가 아니라 58부터? 25+64=89
	이와 같은 수열을 계속 구하다 보면 언젠가 이와 같은 반복수열이 된다. 이떄, 반복되는 부분을 제외했을 때,
	수열에 남게 되는 수들의 개수를 구하는 프로그램을 작성하시오.
	A(1<= A <= 9999), P(1<=P<=5)
	3자리수 4자리수 나올때는? 13->1 133->1 1333->1 ex) A=9999 P=5 -> 59049 * 4 = 236196 <-배열의 크기
	*/
	
	int a;
	cin >> a >> p;
	
	dfs(a);
	int ans = 0;
	for(int i = 0; i < 236197; ++i){
		if(visited[i] == 1)
			ans++;
	}
	cout << ans << endl;
	
	return 0;
}