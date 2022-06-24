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

	Node * node = head;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < k-1; ++j){
			node = node->next;
		}
		cout << node->data << endl;
		node->prev->next = node->next;
		node->next->prev = node->prev;
		node = node->next;
	}
	
	
	
	return 0;
}