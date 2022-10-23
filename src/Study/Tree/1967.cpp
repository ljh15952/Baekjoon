#include <iostream>
#include <vector>
//#include <pair>
#include <memory.h>

using namespace std;

vector<pair<int,int>> node[10002];
bool visited[10002];

int result = 0;
int endPoint = 0;

void dfs(int p, int len){
	if(visited[p])
		return;
	
	visited[p] = true;
	if(result < len){
		result = len;
		endPoint = p;
	}
	
	for(int i = 0; i < node[p].size(); i++){
		dfs(node[p][i].first, len + node[p][i].second);
	}
	
}

int main(){
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n-1; i++){
		int a,b,c;
		cin >> a >> b >> c;
		node[a].push_back({b,c});
		node[b].push_back({a,c});
	}
	
	dfs(1,0);
	
	result = 0;
	memset(visited, false, sizeof(visited));
	
	dfs(endPoint, 0);
	
	cout << result;
	
	return 0;
}


/*
트리는 사이클이 없는 무방향 그래프이다.
트리에서는 어떤 두 노드를 선택해도 둘 사이에
경로가 항상 하나만 존재하게 된다.
트리에서 어떤 두 노드를 선택해서 양쪽으로 쫙 당길 때,
가잘 길게 늘어나는 경우가 있을 것이다.
이럴 때 트리의 모든 노드들은 이 두노드를 지름의 끝 점으로
하는 원 안에 들어가게 된다.
이런 두 노드 사이의 경로의 길이를 트리의 지름이라고 한다.
입력으로 루트가 있는 트리를 가중치가 있는 
간선들로 줄 때 트리의 지름을 구해서 출력하는 프로그램 작성
트리의 노드는 1부터 n까지 번호가 매겨져 있다.

입력 



*/