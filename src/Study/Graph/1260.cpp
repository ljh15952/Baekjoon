#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,v;
vector<int> graph[10001];

void dfs(int k){
	
}

void bfs(int k){
	
}

int main(){
	
	cin >> n >> m >> v;
	
	for(int i = 0; i < m; ++i){
		int s,e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	
	dfs(v);
	cout << endl;
	bfs(v);

	return 0;
}