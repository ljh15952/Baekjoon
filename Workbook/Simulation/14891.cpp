#include <bits/stdc++.h>

using namespace std;

list<char> wheel[5]; // 1 2 3 4 번 톱니바퀴 사용
int K;

void rotate(int i, int r){
	
	if(r == -1){
		wheel[i].push_back(wheel[i].front());
		wheel[i].pop_front();
	}else if(r == 1){
		wheel[i].push_front(wheel[i].back());
		wheel[i].pop_back();
	}
	
	
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
		
		
		//돌리는 코드
		rotate(w, r);
	}
	
	cout << '\n';
	for(int i = 1; i < 5; i++){
		for(auto it : wheel[i]){
			cout << it;
		}
		cout << '\n';
	}
	
	
	
	return 0;
}

/*
1번 톱니바퀴 2번 톱니바퀴 w 변수값 
N극은 0 S극은 1
1. 일단 정해진 톱니바퀴 돌림
2. 그 양옆의 톱니바퀴 돌릴지 말지 판단후 돌려야 되면 돌림
3. 또 그 옆에 톱니바퀴 돌릴지 말지 판단

다 돌린후 각 톱니바퀴 배열의 0번지 값으로 점수 매겨서 결과값 출력

*/
