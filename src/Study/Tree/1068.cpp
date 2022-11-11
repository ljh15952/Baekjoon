#include <iostream>
#include <vector>

using namespace std;

class Node{
	public:
		vector<Node*> children;		
};

int n;
vector<Node*> Tree;

void Traversal(){
	for(int i = 0; i < n; ++i){
		int k = Tree[i]->children.size();
		cout << k << endl;
	}
}

int main(){

	cin >> n;
	
	
	for(int i = 0; i < n; ++i){
		int t;
		cin >> t;
		Node * n = new Node();
		Tree.push_back(n);
		if(t != -1){
			Tree[t]->children.push_back(n);
		}
		
	}
	
	Traversal();
	
	return 0;
}

/*
트리에서 리프 노드란, 자식의 개수가 0인 노드
트리가 주어졌을 때 노드 하나를 지운다. 그 때 남은 트리에서 리프 노드의 개수를
구하는 프로그램을 작성 노드를 지우면 그 노드와 노드의 모든 자손이 트리에서 제거

트리의 노드의 개수 N이 주어짐 50보다 작거나 같은 자연수
다음 줄
0번 노드부터 N-1번 노드까지, 각 노드의 부모가 주어짐
부모가 없다면(루트) -1이 주어짐
셋째 줄에는 지울 노드의 번호가 주어짐

5
-1 0 0 1 1
0번 노드 -1
1번 노드 0
2번 노드 0
3번 노드 1
4번 노드 1
2(2번 노드를 지운다)

*/