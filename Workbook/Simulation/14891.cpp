#include <bits/stdc++.h>

using namespace std;

vector<char> wheel[5]; // 1 2 3 4 번 톱니바퀴 사용
bool isvisited[5];
int K;

void rotate(int i, int r){
	// index로 접근하기 위해 wheel 자료구조 vector로 변경
	if(r == -1){
		wheel[i].push_back(wheel[i].front());
		wheel[i].erase(wheel[i].begin());
	}else if(r == 1){
		wheel[i].insert(wheel[i].begin(), wheel[i].back());
		wheel[i].pop_back();
	}
}

void canRotate(int k, int r){
	
	isvisited[k] = true;
	
	if(k - 1 >= 1 && !isvisited[k-1] && wheel[k][6] != wheel[k - 1][2])
		canRotate(k - 1, r * -1);
	if(k + 1 <= 4 && !isvisited[k+1] && wheel[k][2] != wheel[k + 1][6])
		canRotate(k + 1, r * -1);
	
	rotate(k, r);
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	for(int i = 1; i < 5; i++){
		string s;
		cin >> s;
		
		for(auto it : s){
			wheel[i].push_back(it);
		}
	}	
	
	cin >> K;
	
	for(int i = 0; i < K; i++){
		int w, r; // wheel num, rotate (1 ->) (-1 <-)
		cin >> w >> r;
		fill(isvisited, isvisited+5, false);
		canRotate(w, r);
		
	}
	
	int ans = 0;
	int add = 1;
	for(int i = 1; i < 5; i++){
		if(wheel[i][0] == '1')
			ans += add;
		add *= 2;
	}
	cout << ans << '\n';
	
	return 0;
}



/*
1번 톱니바퀴 2번 톱니바퀴 w 변수값 
N극은 0 S극은 1
1. 일단 정해진 톱니바퀴 돌림
2. 그 양옆의 톱니바퀴 돌릴지 말지 판단후 돌려야 되면 돌림
3. 또 그 옆에 톱니바퀴 돌릴지 말지 판단

다 돌린후 각 톱니바퀴 배열의 0번지 값으로 점수 매겨서 결과값 출력

2번지로 옆에것도 돌려야되는지 확인

if(w == 1){
	flag[1] = true;
	if(wheel[1] != wheel[2]){
		flag[2] = true;
		if(wheel[2] != wheel[3]){
			flag[3] = true;
			if(wheel[3] != wheel[4]){
				flag[4] = true;
			}
		}
	}
}
-> 재귀로 충분히 만들 수 있겠는데?
양 옆으로


*/
