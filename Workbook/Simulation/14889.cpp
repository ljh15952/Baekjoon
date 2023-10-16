#include <bits/stdc++.h>

using namespace std;

int N;
int arr[21][21];
int visited[21];

queue<int> team1;
queue<int> team2;

void calculate(){
	for(int i = 0; i < 2; i++){
		int q = team1.front();
		team1.pop();
		visited[q] = false;
		
		int p = team2.front();
		team2.pop();
		visited[p] = false;
		
		cout << q << ' ' << p << '\n';
	}
}

void backTreacking(){

	if(team1.size() >= 2 && team2.size() >= 2){
		calculate();
		return;
	}
	
	for(int i = 0; i < N; i++){
		if(visited[i])
			continue;
		visited[i] = true;
		
		if(team1.size() < 2)
			team1.push(i);
		else
			team2.push(i);
		backTreacking();

	}
	
	
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> arr[i][j];
		}
	}
	
	backTreacking();
	
	return 0;
}

/*

스타트팀, 링크 팀
1 2		3 4
1 3		2 4
1 4		2 3
N=4이고, S가 아래와 같은 경우
	j	1	2	3	4
i
1			1	2	3
2		4		5	6
3		7	1		2
4		3	4	5
예를 들어 1,2번이 스타트 팀, 3 4번이 링크 팀에 속한 경우 두 팀의 능력치
스타트 팀: S12 + S21 = 1 + 4 = 5
링크 팀: S34 + S43 = 2 + 5 = 7

스타트팀과 링크 팀의 늘력치 차이를 최소로 하려고 한다.
*/