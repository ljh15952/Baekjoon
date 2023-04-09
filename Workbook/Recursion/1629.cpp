#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// ll pow(ll a, ll b, ll c){
// 	if(b == 1) return a % c;
// 	ll val = pow(a, b/2, c);
// 	val = val * val % c;
// 	if(b % 2 == 0) return val;
// 	return val * a % c;
// }













ll pow(ll a, ll b, ll m){
	if(b == 1) return a % m;
	ll val = pow(a, b / 2, m);
	val = val * val % c;
	if(b % 2 == 0) return val;
	return val * a % c; // 2k+1
	
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	ll a,b,c;
	cin >> a >> b >> c;
	
	cout << pow(a, b, c) << '\n';
	
	return 0;
}

/*
자연수 A를 B번 곱한 수를 알고 싶다.
단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를
구하는 프로그램을 작성하시오
A,B,C 모두 20억 이하의 자연수
B번 거듭제곱 해야되는데 20억번만큼 거듭제곱하면 0.5초만에 절때 못함;;

존나 어렵네
내일 할게요
*/