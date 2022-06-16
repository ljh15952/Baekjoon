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
	private:
		int value;
		Node * next;
};

class Queue{
	public:
		void push(){
			int n;
			cin >> n;
			cout << n;
		}
	
		int pop(){
			return 0;
		}
	
		int size(){
			return _size;
		}
	
		int empty(){
			return (_size == 0) ? 0 : 1;
		}
	
		int front(){
			return _head->getValue();
		}
	
		int back(){
			return _tail->getValue();
		}
	
	private:
		int _size;
		Node * _head;
		Node * _tail;
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