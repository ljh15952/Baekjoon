#include <bits/stdc++.h>

using namespace std;

int cube[5][5][5];

int num[5];
bool isUsed[5];
int ct = 0;

void func(int k){
	
	if(k == 5){
		cout << ct++ << '\n';
		for(int i = 0; i < 5; i++)
			cout << num[i];
		cout << '\n';
		return;
	}
	
	for(int i = 0; i < 5; i++){
		
		if(isUsed[i])
			continue;
		
		num[k] = i;
		isUsed[i] = true;
		func(k+1);
		isUsed[i] = false;
	}
	
	
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	// for(int z = 0; z < 5; z++){
	// 	for(int y = 0; y < 5; y++){
	// 		for(int x = 0; x < 5; x++){
	// 			cin >> cube[z][y][x];
	// 		}
	// 	}
	// }
	
	func(0);
	
	// cout << '\n';
	// for(int z = 0; z < 5; z++){
	// 	for(int y = 0; y < 5; y++){
	// 		for(int x = 0; x < 5; x++){
	// 			cout << cube[z][y][x] << ' ';
	// 		}
	// 		cout << '\n';
	// 	}
	// 	cout << '\n';
	// }
	
	return 0;
}

/*
0 1 2 3 4


*/

/*

주어진 5개의 판으로 가능한 미로를 모두 백트래킹으로 만듬
하나 만들고 하나 탈출 해보고 하나 만들고 하나 탈출 해보고
입구가 [0][0][0] 일 경우 출구는 [4][4][4]
[0][4][4] -> [4][0][0]
[0][0][4] -> [4][4][0] 모든 원소가 그냥 반대가 되네!
입구는 4가지의 경우의 수가 있는 듯?
입구가 정해지면 출구가 하나 밖에 나올 수 없다면 

*/

/*
16985 Maze
3차원 미로 탈출..

5x5 크기의 판 5개
일부 칸은 참가자가 들어갈 수 있고, 일부 칸은 들어갈 수 없다. 
하얀 칸은 들어갈 수 있음, 검은칸은 없음 

참가자는 주어진 판들을 시계 방향, 혹은 반시계 방향으로 자유롭게 회전할 수 있다. 뒤집기 X

회전을 완료한 후 참가자는 판 5개를 쌓는다.
판을 쌓는 순서는 참가자가 자유롭게 정할 수 있다.
이렇게 판을 5개 쌓아 만들어진 5x5x5 크기의 큐브가 참가자들을 위한 미로이다.
큐브의 입구는 정육면체에서 참가자가 임의로 선택한 꼭짓점에 위치한 칸이고
출구는 입구와 면을 공유하지 않는 꼭짓점에 위치한 칸이다.

참가자는 현재 위치한 칸에서 면으로 인접한 칸이 참가자가 들어 갈 수 있는 칸인 경우 그 칸으로 이동 가능
참가자 중 본인이 설계한 미로를 가장 적은 이동 횟수로 탈출한 사람이 우승
만약 미로의 입구 혹은 축구가 막혀있거나, 입구에서 출구에 도달할 수 있는 방법이 존재하지 않을 경우에는 탈출이 불가능한 것으로 간주한다.

주어진 판에서 가장 적은 이동 횟수로 출구에 도달할 수 있게끔 미로를 만들었을 때 몇 번 이동을 해야하는지 구해보자

*/