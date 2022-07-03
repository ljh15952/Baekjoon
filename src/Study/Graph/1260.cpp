#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m,v;
vector<int> graph[10001];
bool visited_1[1001];
bool visited_2[1001];

void dfs(int k){
	
	cout << k << " ";
	visited_1[k] = true;
	
	for(int i = 0; i < graph[k].size(); ++i){
		int now = graph[k][i];
		if(visited_1[now] == false)
			dfs(now);
	}
}

void bfs(int k){
	
	queue<int> q;
	q.push(k);
	visited_2[k] = true;
	
	while(!q.empty()){
		
		int x = q.front();
		q.pop();
		cout << x << " ";
		
		for(int i = 0; i < graph[x].size(); ++i){
			int now = graph[x][i];
			if(visited_2[now] == false){
				q.push(now);
				visited_2[now] = true;
			}
		}
		
	}
}

int main(){
	
	cin >> n >> m >> v;
	
	for(int i = 0; i < m; ++i){
		int s,e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	
	for(int i = 1; i < m; ++i){
		sort(graph[i].begin(),graph[i].end());
	}
	
	dfs(v);
	cout << endl;
	bfs(v);

	return 0;
}