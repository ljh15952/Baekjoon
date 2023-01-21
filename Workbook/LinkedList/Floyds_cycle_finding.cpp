#include <bits/stdc++.h>

using namespace std;

class Node{
	public:
		Node(int v) : value(v) {}
		Node * next = nullptr;
		int value = 0;
};

void travaler(Node * s){
	Node * t1 = s;
	Node * t2 = s;
	while(1){
		if(t1->next == nullptr || t2->next == nullptr){
			break;
		}
		t1 = t1->next;
		t2 = t2->next->next;
		cout << t1->value << ' ' << t2->value << '\n';
		if(t1 == t2){
			cout << "Is is cycle List" << '\n';
			break;
		}
	}
	
}

int main(){
	Node * n1 = new Node(1);
	Node * n2 = new Node(2);
	Node * n3 = new Node(3);
	Node * n4 = new Node(4);
	Node * n5 = new Node(5);
	
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n3;
	
	travaler(n1);
}

/*
1 -> 2 -> 3 -> 4 -> 5
          |        |
					|				 |
						<- <-
*/