#include <iostream>
#include <map>

using namespace std;

class Node{
	public:
		Node(char c) : data(c) {};
		char data;
		Node * left;
		Node * right;
};


void PreOrder(Node * n){
	if(n == nullptr)
		return;
	cout << n->data;
	PreOrder(n->left);
	PreOrder(n->right);
}

void InOrder(Node * n){
	if(n == nullptr)
		return;
	InOrder(n->left);
	cout << n->data;
	InOrder(n->right);
}

void PostOrder(Node * n){
	if(n == nullptr)
		return;
	PostOrder(n->left);
	PostOrder(n->right);
	cout << n->data;
}

int main(){
	
	int n;
	cin >> n;
	
	map<char, Node*> m;
	
	
	for(int i = 0; i < n; ++i){
		m.insert({char(65+i), new Node(char(65+i))});	
	}
	
	// for(auto it : m){
	// 	cout << it.first << " " << it.second->data << endl;
	// }
	
	Node * root = nullptr;
	
	for(int i = 0; i < n; ++i){
		char c, l, r;
		cin >> c >> l >> r;
		
		if(root == nullptr)
			root = m[c];
		if(l != '.')
			m[c]->left = m[l];
		if(r != '.')
			m[c]->right = m[r];
	}
	
	PreOrder(root);
	cout << endl;
	InOrder(root);
	cout << endl;
	PostOrder(root);
	cout << endl;
	return 0;
}