#include <iostream>

using namespace std;

int main(){
	
	cout << "2225!" << endl;
	
	/*
	합 분해
	0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램
	덧셈 순서가 바뀐 경우는 다른 경우로 센다(1+2,2+1)
	한 개의 수를 여러 번 쓸수도 있다.
	
	N: 20 K : 2입력
	0부터 20까지의 정수 2개를 더해서 합이 20이 되는 경우의 수
	0+20
	1+19
	2+18
	3+17
	4+16
	5+15
	6+14
	7+13
	8+12
	9+11
	10+10 ----순서를 바꿔도 같은 분기점
	20+0
	19+1
	18+2 .... 21개
	*/
	return 0;
}