#include <bits/stdc++.h>

using namespace std;

int N;
int arr[21][21];
int visited[21];

vector<int> team1;
vector<int> team2;

void calculate(){
	for(int i = 0; i < 2; i++){
		int q = team1[i];

		cout << q << ' ';
	}
	cout << "    ";
	for(int i = 0; i < 2; i++){
		int p = team2[i];

		cout << p << ' ';
	}
	cout << '\n';	
}

void backTreacking(int k){

	if(team1.size() >= 2 && team2.size() >= 2){
		calculate();
		return;
	}
	for(int i = k; i < N; i++){
		if(visited[i])
			continue;
		visited[i] = true;
		
		
		bool flag = false;

		if(team1.size() < 2){
			flag = true;
			team1.push_back(i);
		}
		else{
			team2.push_back(i);
		}
		
		backTreacking(k+1);
		
		if(flag){
			team1.pop_back();
		}
		else
			team2.pop_back();
		
		visited[i] = false;

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
	
	backTreacking(0);
	
	return 0;
}

/*
스타트팀, 링크 팀

1 2		3 4
1 2		3 5
1 2		3 6
1 2		4 5
1 2		4 6
1 2		5 6

1 3		2 4
1 3		2 5
1 3		2 6
1 3		4 5
1 3		4 6
1 3		5 6

1 4
1 5
1 6

2 3
2 4
2 5
2 6

3 4
3 5
3 6

4 5
4 6

5 6
*/