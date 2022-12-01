#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n,c;
	cin >> n >> c;


	queue<pair<int, int>> q;
	priority_queue<int> pq;

	for(int i = 0; i < n; ++i){
		int t;
		cin >> t;
		q.push({i, t});
		pq.push(t);
	}
	int ct = 0;
	while(!pq.empty()){
		int idx = q.front().first;
		int val = q.front().second;
		
		q.pop();
		if(val == pq.top()){
		    pq.pop();
		    ct++;
		    if(idx == c){
		        cout << ct << endl;
		        break;
		    }
		}else{
		    q.push({idx,val});
		}
	}
	return 0;
}
