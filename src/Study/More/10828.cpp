#include <iostream>
#include <string>
using namespace std;

int Stack[10000];
int Size = 0;

void push(){
	int n;
	cin >> n;
	
	Stack[Size++] = n;
}

int pop(){
	if(Size == 0)
		return -1;
	else
		return Stack[--Size];
}

int size(){
	return Size;
}

int empty(){
	if(Size==0)
		return 1;
	else
		return 0;
}

int top(){
	if(Size==0)
		return -1;
	else
		return Stack[Size-1];
}

int main(){

	int n;
	cin >> n;
	
	
	string str;
	for(int i = 0; i < n; ++i){
		cin >> str;
		if(str.compare("push")==0){
			push();
		}else if(str.compare("pop")==0){
			cout << pop() << endl;
		}else if(str.compare("size")==0){
			cout << size() <<endl;
		}else if(str.compare("empty")==0){
			cout << empty() << endl;
		}else if(str.compare("top")==0){
			cout << top() << endl;
		}
	}

	return 0;
}