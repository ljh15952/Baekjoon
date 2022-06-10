#include <iostream>
#include <string>

using namespace std;

int Stack[10000];

void push(){
	
}

void pop(){
	
}

void size(){
	
}

void empty(){
	
}

void top(){
	
}

int main(){

	int n;
	cin >> n;
	
	
	string str;
	for(int i = 0; i < n; ++i){
		cin >> str;
		switch(str){
			case "push":
				push();
				break;
			case "pop":
				cout << pop() << endl;
				break;
			case "size":
				cout << size() <<endl;
				break;
			case "empty":
				cout << empty() << endl;
				break;
			case "top":
				cout << top() << endl;
				break;
		}
	}

	return 0;
}