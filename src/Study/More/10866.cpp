#include <iostream>

using namespace std;

class Node{
	public:
		Node(int i) : n(i) {};
		void setNextNode(Node * node){
			next = node;
		}
		int getValue(){
			return n;
		}
		Node * getNextNode(){
			return next;
		}
	private:
		int n;
		Node * next = nullptr;
};

class Deque{
	public:
		void push_front(){
			int i;
			cin >> i;
			Node * node = new Node(i);
			if(front == nullptr){
				front = node;
				back = node;
			}else{
				node->setNextNode(front);
				front = node;
			}
			Size++;
		}
		
		void push_back(){
			int i;
			cin >> i;
			Node * node = new Node(i);
			if(front == nullptr){
				front = node;
				back = node;
			}else{
				back->setNextNode(node);
				back = node;
			}
			Size++;
		}
	
		int pop_front(){
			if(empty() == 1)
				return -1;
			int n = front->getValue();
			front = front->getNextNode();
			Size--;
			return n;
		}
	
		int size(){
			return Size;
		}
	
		int empty(){
			return (Size == 0) ? 1 : 0;
		}
		
		int pop_back(){
			if(empty() == 1)
				return -1;
			int n = back->getValue();
			back = nullptr;
			Size--;
			return n;
		}
	
		int Front(){
			if(empty() == 1)
				return -1;
			return front->getValue();
		}
	
		int Back(){
			if(empty() == 1)
				return -1;
			return back->getValue();
		}
	
	private:
		Node * front = nullptr;
		Node * back = nullptr;
		int Size = 0;
};


int main(){
	
	
	int n;
	cin >> n;
	
	Deque deque;
	
	string str;
	for(int i = 0; i < n; ++i){
		cin >> str;
		if(str.compare("push_front")==0){
			deque.push_front();
		}else if(str.compare("push_back")==0){
			deque.push_back();
		}else if(str.compare("pop_front")==0){
	 		cout << deque.pop_front() <<endl;
	 	}else if(str.compare("pop_back")==0){
			cout << deque.pop_back() << endl;
		}else if(str.compare("size")==0){
			cout << deque.size() << endl;
		}else if(str.compare("empty") == 0){
			cout << deque.empty() << endl;
		}else if(str.compare("front") == 0){
			cout << deque.Front() << endl;
		}else if(str.compare("back") == 0){
			cout << deque.Back() << endl;
		}
	}
	
	return 0;
}