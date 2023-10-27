#include <bits/stdc++.h>

using namespace std;

int N;
int arr[21][21];
int visited[21];

int team1[12];
int team2[12];

int ans = 10000000;

void calculate(){
	
	int temp1 = 0;
    int temp2 = 0;
	
	 for (int i = 0; i < N; i++){
        if(visited[i]){
            team1[temp1] = i;
            temp1++;
        }else{
            team2[temp2] = i;
            temp2++;
    	}
    }
	
	temp1 = 0;
    temp2 = 0;
    for (int j = 0; j < N/2 - 1; j++)
    {
        for (int k = j + 1; k < N/2; k++)
        {
            temp1 += arr[team1[j]][team1[k]] + arr[team1[k]][team1[j]]; // 1번 팀 능력치
            temp2 += arr[team2[j]][team2[k]] + arr[team2[k]][team2[j]]; // 2번 팀 능력치
        }
    }
    int sub = abs(temp1 - temp2);
	ans = min(ans, sub);
	
}

void backTreacking(int k, int cnt){
	
	if(cnt == N/2){
		calculate();
		return;
	}
	for(int i = k; i < N; i++){
		if(visited[i])
			continue;
		visited[i] = true;
		backTreacking(i+1, cnt + 1);
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
	backTreacking(0,0);
	cout << ans << '\n';
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