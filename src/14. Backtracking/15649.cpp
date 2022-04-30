#include <iostream>

using namespace std;


int n,m;
int arr[9];
bool visited[9];

void dfs(int k){
	if(k == m){
		for(int i = 0; i < m; ++i){
			cout << arr[i] << " ";
		}
		cout << "\n";
	}else{
		for(int i = 1; i <= n; ++i){
			if(!visited[i]){
				visited[i] = true;
				arr[k] = i;
				dfs(k+1);
				visited[i] = false;
			}
		}
	}
}


int main(){
	cin >> n >> m;
	dfs(0);
	return 0;
}