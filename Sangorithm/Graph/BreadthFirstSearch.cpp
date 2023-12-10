#include <iostream>
#include <queue>

using namespace std;


int arr[7][7] = {
	{0,0,0,0,0,0,0},
	{0,0,1,1,0,1,0},
	{0,1,0,1,0,0,0},
	{0,1,1,0,1,1,1},
	{0,0,0,1,0,0,1},
	{0,1,0,1,0,0,0},
	{0,0,0,1,1,0,0}
};

bool isVisited[7];

void BFS(int k){
	
	queue<int> q;
	
	q.push(k);
	isVisited[k] = true;

	while(!q.empty()){
		
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		
		for(int i = 1; i <= 6; i++){
			if(isVisited[i]) continue;
			
			if(arr[cur][i]){
				q.push(i);
				isVisited[i] = true;
			}
		}
	}
}

int main(){
	
	BFS(1);
	cout << endl;
	
	return 0;
}

/*

너비 우선 탐색
시작 정점에 인접한 정점들을 모두 방문한 뒤에 이 정점들에 인접한 방문안한 정점들을 모두 방문한다.
시작 정점에 연결된 모든 정점들을 방문할 때까지 계속
탐색이 종료된 후 아직 방문안한 정점들이 남아 있다면 그 정점들 중 한 정점에서 너비 우선 탐색 다시 시작


*/