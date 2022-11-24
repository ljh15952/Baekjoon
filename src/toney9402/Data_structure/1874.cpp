#include <iostream>

using namespace std;

int main(){
	
	cout << "1874" << endl;
	
	return 0;
}

/*
스택 수열
1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만든다.
이때 스택에 push하는 순서는 반드시 오름차순을 지키도록 하자

pop을 해야되는 수가 현재 top값보다 작으면 NO를 출력하는 방향?

1 2 5 3 4를 만드려면?

+ - + - + + + -

stack
3 4 
output
1 2 5
*/