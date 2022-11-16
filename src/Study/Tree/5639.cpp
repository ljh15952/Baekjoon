#include <iostream>
#include <vector>

using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node * insert(Node * node, int data){
	if(node == nullptr){

	}
}

void postOrder(int start, int end){
	
}

int main(){
	
	int a;
	while(cin >> a){
		Tree.push_back(a);
	}
	
	postOrder(0, Tree.size());

	
	/*
	리눅스 환경이라 ctrl+d로 EOF입력하여 입력을 종료한다.
	*/
	return 0;
}

/*
이진 검색 트리

이전 검색 트리는 다음과 같은 세 조건을 만족하는 이진 트리이다.
노드의 왼쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 작다.
노드의 오른쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 크다
왼쪽 오른쪽 서브트리도 이진 검색 트리이다.

전외 순회, 후위 순회
전위 순회한 결과가 주어졌을 때 
이 트리를 후위 순회한 결과를 구하는 프로그램을 작성

같은 키를 가지는 노드는 없이 입력이 주어진다

입력 50 30 24 5 28 45 98 52 60
출력 5 28 24 45 30 60 52 98 50


입력 받은 데로 left값을 채우며 부모보다 큰 값이 입력되면 right을 채우고
그 윗 부모로 올라감
*/