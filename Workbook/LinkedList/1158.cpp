#include <bits/stdc++.h>

using namespace std;

class Node{
	public:
		Node * next = nullptr;
		int data;
};

class List{
	public:
		Node * head = nullptr;
		Node * tail = nullptr;
		void insert(Node * n){
			if(head == nullptr){
				head = n;
				tail = n;
			}else{
				tail->next = n;
				tail = n;
			}
		}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	List * li = new List();
	
	int N, K;
	cin >> N >> K;
	
	for(int i = 1; i <= N; ++i){
		
	}
	
	return 0;
}

/*
1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K가 주어짐
순서대로 k번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라
이 과정을 계속해 나간다. N명 사람이 모두 제거 될 때까지 계속된다
원에서 사람들이 제거되는 순서를 (N,K)요세푸스 순열이라고 한다.
(7, 3)요세푸스 순열
<3, 6, 2, 7, 5, 2, 4>
*/