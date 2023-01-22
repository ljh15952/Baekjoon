#include <bits/stdc++.h>

using namespace std;

int N, K;
queue<int> q;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> K;
	
	for(int i = 1; i <= N; ++i){
		q.push(i);
	}
	
	cout << '<';
	while(1){
		for(int i = 0; i < K-1; ++i){
			q.push(q.front());
			q.pop();
		}
			
		if(q.size() <= 1){
			cout << q.front() << ">\n";
			break;
		}else{
			cout << q.front() << ", ";
			q.pop();
		}
	}
		
	return 0;
}