#include <iostream>
#include "Value.h"

using namespace std;

void heapify(int N, int i){
	
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	if(left < N && arr[left] > arr[largest])
		largest = left;
	
	if(right < N && arr[right] > arr[largest])
		largest = right;
	
	if(largest != i){
		swap(i, largest);
		heapify(N, largest);
	}
}

void heapSort(){
	
	for(int i = n / 2 - 1; i >= 0; i--)
		heapify(n, i);
	print();
	for(int i = n - 1; i >= 0; i--){
		swap(0, i);
		heapify(i, 0);
	}
	
}

int main(){
	
//	print();
	heapSort();
	//print();
	return 0;
}

/*
우선 순위 큐
큐와 유사하지만 항목들이 추가되고
처리되는 순서가 우선 순위에 따라 정해진다. 

FindMax : 우선 순위가 가장 높은 항목 검색
DeleteMax : 우선 순위가 가장 높은 항목 제거
Insert : 새로운 항목을 추가

DeleteMax와 Insert 연산이 수행된 후 또 다른 우선 순위 큐가 만들어진다.

힙 
우선 순퀴 큐의 연산들을 효율적으로 구현한 자료 구조
힙 조건을 만족시키는 완전 이진트리
최대 힙, 최소 힙
최대(최소) 힙의 조건
트리의 각 노드의 값이 자식 노드들의 값보다 크거나(작거나) 같다.
최대힙
힙의 루트 노드부터 잎 까지의 경로상에 있는 노드들의 값들은
내림차순으로 정렬되어 있음

힙의 특성
n개의 노드를 가진 힙의 높이 = logN
힙의 루트 노드는 항상 최댓값을 저장
힙의 한 노드와 자손 노드들로 이루어진 부분 트리도 힙

힙 배열 포현
0 1 2 3 4 5 6 7 8 9 10
- 8 7 6 5 3 4 5 2 4 2

힙 정렬
1. 주어진 배열을 힙으로 만든다.
2. (남은) 힙에서 루트 노드(최댓값)을 제거한다.
-> 2단계는 (n-1)번 수행
2.2 트리에서 마지막 노드를 제거
2.3 남은 트리를 힙으로 만든다.
-> 제거된 값들은 배열의 뒷부분에 순서대로 저장한다.

힙 조건 확인
두 개의 자식 노드 y와 z만을 가진다
A[x] >= A[y] && A[x] >= A[Z] -> x에서 힙 조건 만족 그대로 둠
그렇지 않으면 A[x]를 A[y],A[z] 중 큰 값과 교환


*/