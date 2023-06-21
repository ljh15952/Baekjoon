#include <bits/stdc++.h>

using namespace std;

int L, C;

char chars[17];
char arr[17];

bool aeiou(char t){
	return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
}

void func(int k, int st){
	
	if(k == L){
		int cnt1 = 0;
		int cnt2 = 0;
		
		for(int i = 0; i < L; ++i){
			if(aeiou(arr[i])) cnt1++;
			else cnt2++;
		}
		
		if(cnt1 >= 1 && cnt2 >= 2){
			for(int i = 0; i < L; ++i){
				cout << arr[i];
			}
			cout << '\n';
		}
		return;
	}
	
	for(int i = st; i < C; ++i){
		arr[k] = chars[i];
		func(k+1, i+1);
	}
	
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> L >> C;
	
	for(int i = 0; i < C; ++i){
		cin >> chars[i];
	}
	
	sort(chars, chars + C);
	
	func(0, 0);
	
	return 0;
}

/*
암호만들기

암호 작동 보안시스템
서로 다른 L개의 알파벳 소문자들로 구성되며 최소 한 개의 모음(aeiou)과
최소 두 개의 자음으로 구성되어 있다고 알려져 있다.
정렬된 문자열 증가하는 순서로 배열되었을 것 abc -> O bac -> X

암호로 사용했을 법한 문자의 종류는 C가지가 있다고 한다.
C개의 문자들이 모두 주어졌을 때 가능성 있는 암호들을 모두 구하는 프로그램

4 6 (암호 4글자 6개의 문자들)
a t c i s w


*/