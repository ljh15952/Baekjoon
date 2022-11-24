#include <iostream>

using namespace std;

int Index[100001];
int inorder[100001];
int postorder[100001];
int n;


// preorder 를 출력하는 함수 (재귀)
void getPreOrder(int inStart, int inEnd, int postStart, int postEnd)
{
    // 더 이상 분할 할 수 없는 경우 return
   
    // postorder의 끝 값이 root값
    // Index 배열을 통해 inorder에서의 root index를 쉽게 구할 수 있다.

    // 재귀 함수 호출
    
}

int main(){
	
	// 다시 풀어라
	
	return 0;
}

/*
후위순회의 가장 마지막 값은 루트이다
중위순회의 루트를 기준으로 왼쪽은 왼쪽 서브트리 오른쪽은 오른쪽 서브트리이다.


트리의 순회
n개의 정점을 갖는 이진 트리의 정점에 1부터 n까지의 번호가 중복 없이 매겨져 있다.
이와 같은 이진 트리의 인오더와 포스트오더가 주어졌을 때, 프리오더를 구하는 프로그램 작성

입력
n(1<=n<=100000)
인오더 n개의 자연수
포스트오더 n개의 자연수

출력
첫째 줄에 프리오더를 출력

인오더 = left root right
포스트오더 = left right root
프리오더 = root left right

	2
  /   \
 1     3
*/