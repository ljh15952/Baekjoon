#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

vector<pair<int,int>> tree[10002];

int ans = 0;

int dfs(int x){
	int biglen = 0;
	int len1 = 0;
	int len2 = 0;
	int k;
	
	for(int i = 0; i < tree[x].size(); i++){
		k = dfs(tree[x][i].first) + tree[x][i].second;
		if(k > len1 || k > len2){
			len2 = len1;
			len1 = k;		
		}
		biglen = max(biglen,k);
	}
	
	ans = max(ans, len1+len2);
	
	return biglen;
}

int main(){
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n-1; i++){
		int a,b,c;
		cin >> a >> b >> c;
		tree[a].push_back({b,c});
	}
	
	dfs(1);
	
	cout << ans << endl;
	
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