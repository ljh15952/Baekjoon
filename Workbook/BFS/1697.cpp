#include <bits/stdc++.h>

using namespace std;

#define Y second
#define X first

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int dist[100002];
	fill(dist, dist+100001, -1);
	dist[n] = 0;
	queue<int> Q;
	Q.push(n);
	
	while(dist[k] == -1){
		int cur = Q.front(); Q.pop();
		
		for(int nxt : {cur-1, cur+1, 2*cur}){
			if(nxt < 0 || nxt > 100000) continue;
			if(dist[nxt] != -1) continue;
			dist[nxt] = dist[cur]+1;
			Q.push(nxt);
		}
	}
	
	cout << dist[k] << '\n';
	
	return 0;
}

/*
숨바꼭질
수빈 점 N
동생 점 K
수빈이는 걷거나 순간이동? 할 수 있다.
걷는가면 1초 후 x-1 또는 x+1로 이동, 순간이동 하면 1초 후에 2*x의 위치로 이동
수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇초일까?

0초 5 17
1초 10 17
2초 9 17
3초 18 17
4초 17 17
*/