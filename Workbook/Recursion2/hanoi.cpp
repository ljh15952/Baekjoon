#include <iostream>

using namespace std;

void hanoi(int a, int b, int n){
	if(n == 1){
		cout << a << ' ' << b << '\n';
		return;
	}
	hanoi(a, 6-a-b, n-1);
	cout << a << ' ' << b << '\n';
	hanoi(6-a-b, b, n-1);
}

int main(){
	
	int k;
	cin >> k;
	hanoi(1,3,k);
		
	return 0;
}

/*
진짜 하노이 탑만 풀고 재귀 패스
https://ko.khanacademy.org/computing/computer-science/algorithms/recursive-algorithms/a/the-factorial-function
*/