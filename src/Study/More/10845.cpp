#include <iostream>
#include <string>

using namespace std;

class Node{
	public:
		Node(int a) : value(a) {};
		void setNextNode(Node * n){
			next = n;
		}
		int getValue(){
			return value;
		}
		Node * getNextNode(){
			return next;
		}
	private:
		int value;
		Node * next = nullptr;
};

class Queue{
	public:
		void push(){
			int n;
			cin >> n;
			Node * node = new Node(n);
			if(_head == nullptr){
				_head = node;
				_tail = _head;				
			}else{
				_tail->setNextNode(node);
				_tail = node;
			}
			_size++;
		}
	
		int pop(){
			if(_head == nullptr)
				return -1;
			int n = _head->getValue();
			_head = _head->getNextNode();
			_size--;
			return n;
		}
	
		int size(){
			return _size;
		}
	
		int empty(){
			return (_size == 0) ? 1 : 0;
		}
	
		int front(){
			if(empty() == 1)
				return -1;
			return _head->getValue();
		}
	
		int back(){
			if(empty() == 1)
				return -1;
			return _tail->getValue();
		}
	
	private:
		int _size = 0;
		Node * _head = nullptr;
		Node * _tail = nullptr;
};

int main(){
	
	int n;
	cin >> n;
	
	Queue queue;
	
	string str;
	for(int i = 0; i < n; ++i){
		cin >> str;
		if(str.compare("push")==0){
			queue.push();
		}else if(str.compare("pop")==0){
			cout << queue.pop() << endl;
		}else if(str.compare("size")==0){
			cout << queue.size() <<endl;
		}else if(str.compare("empty")==0){
			cout << queue.empty() << endl;
		}else if(str.compare("front")==0){
			cout << queue.front() << endl;
		}else if(str.compare("back") == 0){
			cout << queue.back() << endl;
		}
	}
	
	return 0;
}