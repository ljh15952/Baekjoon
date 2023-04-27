#include <bits/stdc++.h>

using namespace std;

int num;
int lotto[14];
int ans[6];

void dfs(int start, int depth){
	if(depth == 6){
		for(int i = 0; i < 6; ++i){
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	for(int i = start; i < num; ++i){
		ans[depth] = lotto[i];
		dfs(i + 1, depth + 1);
	}
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	while(cin >> num && num){
		for(int i = 0; i < num; ++i){
			cin >> lotto[i];
		}
		dfs(0, 0);
		cout << '\n';
	}
	
	return 0;
}

/*
테스트
7 1 2 3 4 5 6 7

로또 1..49 까지 수 6개를 고른다.

49가지의 수 중 k(>6)개의 수를 골라 집합 S를 만든 다음
그 수만 가지고 번호를 선택하는 것이다.
k=8 S={1,2,3,5,8,13,21,34} 일 때 
수를 고를 수 있는 경우의 수는 총 28가지이다.

테스트 케이스로 주어진다 
마지막에는 0이 입력된다.

*/