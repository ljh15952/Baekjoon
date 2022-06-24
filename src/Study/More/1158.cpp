#include <iostream>
#include <queue>

using namespace std;


int main(){
	
	int n,k;
	cin >> n >> k;
	
	queue<int> que;
	
	for(int i = 1; i <= n; ++i){
		que.push(i);
	}
	
	cout << "<";
	
	while(que.size()){
		if(que.size () == 1){
			cout << que.front() << ">";
			que.pop();
			break;
		}
		for(int j = 1; j < k; ++j){
			que.push(que.front());
			que.pop();
		}
		cout << que.front() << ", ";
		que.pop();
	}
	
	cout << endl;
	
	return 0;
}