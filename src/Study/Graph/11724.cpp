#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[499501];
bool visited[499501];
int ct = 0;

void dfs(int k){
	visited[k] = true;
	//cout << k << endl;
	
	for(int i = 0; i < graph[k].size(); ++i){
		int next = graph[k][i];
		if(visited[next] == false){
			dfs(next);
		}
	}
}

int main(){

	/*
	연결 요소의 개수
	방향 없는 그래프가 주어졌을 때, 연결요소 (Connected Component)의 개수를 구하는 프로그램
	
	입력
	첫째 줄에 정점의 개수 N과 간선의 개수M이 주어진다.(1 <= N <= 1000, 0 <= M <= N*(n-1)/2)
	둘때 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 <= u, v <= N, u != v) 같은 간선은 한 번만 주어진다.	
	
	출력
	첫째 줄에 연결 요소의 개수를 출력
	
	간선의 최대 수 499500
	
	ex)
	6 5 정점 6개 간선 5개
	
	1 2 1->2
	2 5 2->5
	5 1 5->1
	3 4 3->4
	4 6 4->6
	
	2 연결 요소는 2개
	*/
	
	int N,M;
	cin >> N >> M;
	
	for(int i = 0; i < M; ++i){
		int u,v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for(int i = 1; i <= N; ++i){
		if(visited[i] == false){
			ct++;
			dfs(i);
		}
	}
	cout << ct << endl;
	// for(int i = 1; i <= N; ++i){
	// 	for(int j = 0; j < graph[i].size(); ++j){
	// 		cout << i << " -> " << graph[i][j] << endl;
	// 	}
	// }
	
	return 0;
}