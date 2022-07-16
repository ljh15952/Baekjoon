#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int k){
	visited[k] = true;
	for(int i = 0; i < graph[k].size(); ++i){
		int next = graph[k][i];
		if(visited[next] == false)
			dfs(next);
	}
}

int main(){
	
	/*
	순열사이클
	
	1 2 3 4 5 6 7 8
	3 2 7 8 1 4 5 6
	
	
	1->3
	2->2
	3->7
	4->8
	5->1
	6->4
	7->5
	8->6 
	추가 후 그래프를 살펴보면
	1->3->7->5->1 그래프 1
	2->2 그래프 2
	4->8->6->4
	
	테스트 케이스2 
	1 2 3 4 5 6 7 8 9 10
	2 1 3 4 5 6 7 9 10 8
	1->2	1
	2->1	1
	3->3	2	
	4->4	3
	5->5	4
	6->6	5
	7->7	6
	8->9	7
	9->10	7
	10->8	7
	
	순회하면서 visited가 true라면 순열 사이클 count++을 해준다면?
	*/
	
	int t; //테스트 케이스의 개수
	cin >> t;
	
	
	for(int j = 0; j < t; ++j){
		int n; // 순열의 크기, 간선의 크기라고 봐도 ok
		cin >> n;
		int num;
		for(int i = 1; i <= n; ++i){
			cin >> num;
			graph[i].push_back(num);		
		}
	
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			if(visited[i] == false){
				dfs(i);
				ans++;
			}
		}
		cout << ans << endl;
		
		for(int i = 1; i <= n; ++i){
			graph[i].clear();
			visited[i] = false;
		}
	}
	
	return 0;
}