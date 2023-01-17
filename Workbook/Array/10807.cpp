#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N;
	cin >> N;
	int arr[201] = {};
	for(int i = 0; i < N; ++i){
		int a;
		cin >> a;
		arr[a + 100]++;
	}
	int V;
	cin >> V;
	
	cout << arr[V+100] << '\n';
	
	
	return 0;
}