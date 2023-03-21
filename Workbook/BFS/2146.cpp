#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cout << "QWE";
	
	
	return 0;
}

/*
다리 만들어 버리기
여러 섬으로 이루어진 나라가 있음
섬을 잇는 다리를 만들겠다는 공약
한 섬과 다른 섬을 잇는 다리 하나만을 만들기로 함
또한 그 다리도 가장 짧게 함

NxN크기의 이차원 평면상에 존재
0은 바다 1은 육지
항상 두 개 이상의 섬이 있는 데이터만 

가장 짧은 다리의 길이를 출력

섬 별로 분류 해야 될듯

queue<tuple<int,int,int>>
y,x,t 
t는 태그 0번 섬, 1번 섬, 2번 섬...

1. BFS돌려서 섬별로 태그를 함
2. 육지 BFS돌려서 다른 섬 만날 때 까지 돌림
3. 그냥 모든 거리를 vector한에 저장하고 최소값 출력

1들 큐에 넣은 다음
BFS


*/