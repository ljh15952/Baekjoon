#include <bits/stdc++.h>

using namespace std;

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	int cost[5] = {0,2,5,9,10};
	
	
	int ans[5] = {0, 0, 0, 0, 0};
	ans[1] = cost[1];
	/*
	2, 1 + 1
	3, 2 + 1
	4, 3 + 1, 2 + 2, (2 + 1) + 1, 1 + 1 + 1 + 1
	
	*/
	for(int i = 2; i <= 4; i++){
		ans[i] = max(cost[i], ans[i-1] + cost[4-i]);
	}
	
	cout << ans[4] << '\n';
	
	return 0;
}

/*
막대 자르기 문제

막대의 길이 N
막대는 길이가 i인 조각막대로 자를 수 있다.

길이가 i인 막대의 판매가격은 pi이다.

길이가 n인 막대를 여러 개의 양의 정수 길이의 조각
막대들로 잘라서 판매할 때 얻을 수 있는 최대 판매 금액
자르지 않고 통째로 팔 수 도 있다.


*/