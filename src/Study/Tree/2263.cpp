#include <iostream>

using namespace std;

int main(){
	
	cout << "2263" << endl;
	
	return 0;
}

/*
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
 
 이진트리라는 조건이 있으니 입력된 수에 따라 트리가 몇층인지 계산 한 다음
 쭉쭉 해나간다면?

*/