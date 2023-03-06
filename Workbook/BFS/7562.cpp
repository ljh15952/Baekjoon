#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int nx[6] = {};
int ny[6] = {};

int board[300][300];


int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cout << "QWE" << '\n';
	
	return 0;
}

/*
나이트의 이동

나이트가 이동하려고 하는 칸이 주어진다.
나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까

테스트 케이스의 개수가 주어짐
각 케이스는 세 줄로 이루어져 있다.
체스판의 한 변의 길이 4<=I<=300
크기는 IxI 
둘째 줄과 셋째줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어짐

K * * * * * * *
* * * * * * * *
* 1 * * * * * *
* * * * * * * *
* * 2 * * * * *
* 4 * * * * * *
* * * 3 * * * *
5 * * * * * * *

*/