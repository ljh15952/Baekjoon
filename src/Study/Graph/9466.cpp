#include <iostream>

using namespace std;

int graph[100001];
bool visited[100001];
bool done[100001];
int ans;
int T,n;

void dfs(int k){
	visited[k] = true;
	int next = graph[k];
	
	if(!visited[next])
		dfs(next);
	else if(!done[next]){
		for(int i = next; i != k; i = graph[i]){
			ans++;
		}
		ans++;
	}
	done[k] = true;
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	
	while(T--){
		cin >> n;

		for(int i = 1; i <= n; ++i){
			int t;
			cin >> graph[i];
		}
		
		for(int i = 1; i <= n; ++i){
			if(!visited[i])
				dfs(i);
		}
		
		cout << n-ans << '\n';
		
		for(int i = 1; i <= n; ++i){
			graph[i] = 0;
			done[i] = false;
			visited[i] = false;
		}
		ans = 0;
	}
	
	
	return 0;
}