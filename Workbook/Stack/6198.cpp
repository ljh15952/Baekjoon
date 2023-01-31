#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cout << "ASD" << '\n';
	
	
	return 0;
}

/*
N개의 빌딩
오른쪽으로만 볼 수 있다.
i번째 빌딩 관리인이 볼 수 있는 다른 빌딩의 옥상 정원은 i+1, i+2,,, N이다
자신이 위치한 빌딩보다 높거나 같은 빌딩이 있으면 그 다음에 있는 모든 빌딩의 옥상은 보지 못함
N
6
H
10 3 7 4 12 2
1  2 3 4 5  6

1 -> 2 3 4
2 -> X
3 -> 4
4 -> X
5 -> 6
6 -> X
3 + 1 + 1 = 5

*/