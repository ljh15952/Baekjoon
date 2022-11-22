#include <iostream>

using namespace std;

int main(){
	
	cout << "2164" << endl;
	
	return 0;
}

/*
버리고 아래에 넣기를 반복
N = 6
1 2 3 4 5 6
1버림 2 아래로
3 4 5 6 2
3버림 4 아래로
5 6 2 4
5버림 6 아래로
2 4 6
2버림 4 아래로
6 4
6버림 한장 남았으니 4 출력 (4 아래로 단계 건너 뛰기)


*/