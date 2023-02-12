#include <bits/stdc++.h>

using namespace std;

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N;
	cin >> N;
	
	int ans = 0;
	while(N--){
		string s;
		cin >> s;

		stack<int> st;


		for(auto it : s){
			if(st.empty()) st.push(it);
			else{
				if(st.top() == it){
					st.pop();
				}else{
					st.push(it);
				}
			}
		}
		
		if(st.empty()) ans++;
	}
	
	cout << ans << '\n';
	
	return 0;
}

/*
평석이 오늘 자정까지 보고서 제출
졸다가 제출 마감 1시간 전에 깨고 맘
자는 동안 키보드가 잘못 눌려서 보고서의 모든 글자가 A와 B로 바뀌었다.
그래서 보고서는 때려 치우고 보고서에 좋은 단어나 세보기로 마음 먹었다(?)

A는A끼리 B는B끼리 쌍을 지음
만약 선끼리 교차하지 않으면서 각 글자를 정확히 한 개의 다른 위치에 있는
같은 글자와 짝 지을수 있다면 그 단어는 좋은 단어이다.

첫 째줄에 단어의 수 N이 주어짐
다음 줄 단어 주어짐 2부터 100000 사이
좋은 단어의 수 출력

ABAB

AABB

ABBA

AAA

AA

AB

ABBABB


*/