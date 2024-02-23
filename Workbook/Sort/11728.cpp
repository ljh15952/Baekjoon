#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[1000001];
int B[1000001];

int arr[2000002];

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	for(int i = 0; i < M; i++){
		cin >> B[i];
	}
	
	int a = 0;
	int b = 0;
	int n = 0;
	
	for(int i = 0; i < N+M; i++){
		if(b == M)
			arr[i] = A[a++];
		else if(a == N)
			arr[i] = B[b++];
		else if(A[a] <= B[b])
			arr[i] = A[a++];
		else
			arr[i] = B[b++];
	}
	
	for(int i = 0; i < N+M; i++){
		cout << arr[i] << ' ';
	}
	cout << '\n';,
	
	
	return 0;
}