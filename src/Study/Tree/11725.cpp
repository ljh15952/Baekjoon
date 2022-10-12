#include <iostream>
#include <vector>

using namespace std;

class Node{
	public:
		Node(int d) : data(d) {};
		int data;
		Node * parent;
		vector<Node*> children;
};

vector<Node*> arr;
bool visited[100001];

void dfs(Node * node, Node * parent){
	
	node->parent = parent;
	
	visited[node->data] = true;
	
	int l = node->children.size();
	
	for(int i = 0; i < l; i++){
		int k = node->children[i]->data;
		if(visited[k] == false)
			dfs(node->children[i],node);
	}
	
}


int main(){
	
	int n;
	scanf("%d", &n);
	
	
	for(int i = 1; i <= n; i++){
		Node * n = new Node(i);
		arr.push_back(n);
	}
	
	int a, b;
	for(int i = 1; i < n; i++){
		scanf("%d %d", &a, &b);
		arr[a-1]->children.push_back(arr[b-1]);
		arr[b-1]->children.push_back(arr[a-1]);
	}
	
	dfs(arr[0], nullptr);
	
	for(int i = 1; i < n; i++){
		cout << arr[i]->parent->data << '\n';	
	}
	
	return 0;
}
// 테스트 코드는 통과 -> 시간초과 수정 후 바로 맞춰버리기~
/*
n = 7
n-1 반복
1은 무조건 루트노드 고정
1 6
6 3
3 5
4 1
2 4
4 7
		2 - 4 - 1 - 6 - 3 - 5
			ㅣ
			7
4
6
1
3
1
4

깊이 우선 탐색 조지면서 전 노드를 부모로 추가 하면 될 듯?
양방향 연결은 덤
12
1 2
1 3
2 4
3 5
3 6
4 7
4 8
5 9
5 10
6 11
6 12

			1 - 2 -   4 - 7
			|		  |
			3 - 6-11  8
			|	- 12
			5 - 9
			|
			10
1 
1
2
3
3
4
4
5
5
6
6



출력
n-1개의 노드들의 부모 노드를 2번 노드부터 순서대로 출력


*/