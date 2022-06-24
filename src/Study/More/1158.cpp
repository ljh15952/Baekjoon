#include <iostream>

using namespace std;

class Node{
	public:
		Node(int i) : data(i) {};
		int data;
		Node * prev = nullptr;
		Node * next = nullptr;
};

int main(){
	
	int k,n;
	cin >> n >> k;
	
 	Node * head = nullptr;
	Node * tail = nullptr;
	for(int i = 1; i <= n; ++i){
		if(head == nullptr){
			head = new Node(i);
			tail = head;			
		}else{
			Node * node = new Node(i);
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
	}
	tail->next = head;
	head->prev = tail;

	cout << "<";
	
	Node * node = head;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < k-1; ++j){
			node = node->next;
		}
		if(i == n-1){
			cout << node->data << ">";
		}else{
			cout << node->data << ", ";
		}
		node->prev->next = node->next;
		node->next->prev = node->prev;
		node = node->next;
	}
	
	
	
	return 0;
}

// #include <iostream>
// #include <queue>

// using namespace std;


// int main(){
	
// 	int n,k;
// 	cin >> n >> k;
	
// 	queue<int> que;
	
// 	for(int i = 1; i <= n; ++i){
// 		que.push(i);
// 	}
	
// 	cout << "<";
	
// 	while(que.size()){
// 		if(que.size () == 1){
// 			cout << que.front() << ">";
// 			que.pop();
// 			break;
// 		}
// 		for(int j = 1; j < k; ++j){
// 			que.push(que.front());
// 			que.pop();
// 		}
// 		cout << que.front() << ", ";
// 		que.pop();
// 	}
	
// 	cout << endl;
	
// 	return 0;
// }