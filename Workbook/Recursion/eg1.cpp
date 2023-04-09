#include <iostream>

using namespace std;

using ll = long long;

ll func1(ll a,ll b, ll m){
	ll val = 1;
	while(b--) val = val * a % m;
	return val;
}

int main(){
	
	// 연습문제 거듭제곱
	// a의b제곱을 m으로 나눈 나머지를 구해보자
	
	cout << func1(6,50,5) << '\n';
	
	return 0;
}