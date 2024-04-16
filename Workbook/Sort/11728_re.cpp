<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

int A[1000001];
int B[1000001];

int N, M;

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	for(int i = 0; i < M; i++){
		cin >> B[i];	
	}
	
	for(int i = 0; i < N; i++){
		cout << A[i] << ' ';
	}
	cout << '\n';
	
	for(int i = 0; i < M; i++){
		cout << B[i] << ' ';
	}
	cout << '\n';
	
	
	
	
	return 0;
}
=======

>>>>>>> fe2deb7831239de79903da74ee2616044b4c3325
