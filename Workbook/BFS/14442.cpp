#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cout << "QWE" << '\n';
	
	return 0;
}

/*
NxM의 행렬로 표현되는 맵
0은 이동할 수 있는 곳, 1은 이동할 수 없는 벽
(1,1)에서 (N,M)의 위치까지 이동하려 함(최단경로)
시작하는 칸, 끝나는 칸도 포함해서 센다.

만약 이동하는 도중 벽을 부수고 이동하는 것이 좀 더 경로가 짧다면
벽을 K개 까지 부수고 이동하여도 된다.

N, M, K
1,1과 N,M은 항상 0이다

*/