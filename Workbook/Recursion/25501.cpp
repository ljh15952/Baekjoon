#include <bits/stdc++.h>

using namespace std;

int ct = 0;
char word[1001];
int recursion(char * s, int l, int r){
	ct++;
	if(l >= r) return 1;
	else if(s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(char * s){
	return recursion(s, 0, strlen(s) - 1);
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N;
	cin >> N;
	
	while(N--){
		cin >> word;
		ct = 0;
		cout << isPalindrome(word) << ' ' << ct << '\n';
	}
		
	return 0;
}

/*
재귀의 귀재
팬린드롬->
앞에서부터 읽었을 때와 뒤에서부터 읽었을 때가 같은 문자열
AAA, ABBA, ABABA
어떤 문자열이 팰린드롬인지 판별하는 문제는 재귀 함수를 이용해 쉽게 해결할 수 있다.



*/