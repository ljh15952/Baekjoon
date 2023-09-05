#include <bits/stdc++.h>

using namespace std;

int N, M; // 행 열
int Map[501][501];

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> Map[i][j];
		}
	}
	
	cout << '\n';
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << Map[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}

/*

테트리미노

폴리오미노 크기가 1x1인 정사각형을 여러 개 이어서 붙인 도형
다음과 같은 조건 만족
정사각형은 서로 겹치면 안된다.
도형은 모두 연결되어 있어야 한다.
정사각형의 변끼리 연결되어 있어야 한다. 

NxM인 종이 위에 테트로미노 하나를 놓으려한다.
종이는 1x1 크기의 칸 각각의 칸에는 정수가 하나 쓰여있음

테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램
테트로미노 회전, 대칭시켜도 된다.


*/