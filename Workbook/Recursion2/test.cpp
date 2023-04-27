#include <iostream>

using namespace std;

/*
	입력 받은 수 부터 1까지 출력하는 재귀 함수
	1을 출력할 수 있다.
	
*/
void func1(int i){
	if(i == 0)	return;
	cout << i << ' ';
	func1(i-1);
}


/*
1부터 n까지 더한 수를 출력

*/

int func2(int i){
	if(i == 1) return 1;
	return i + func2(i-1);
}

int main(){
	
	func1(5);
	
	cout << '\n';
	
	cout << func2(10) << '\n';
	
	return 0;
}