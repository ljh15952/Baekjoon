#include <iostream> 

using namespace std;

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	return 0;
}

/*
총 F층으로 이루어진 고층 건물에 사무실
스타트링크가 있는 곳의 위치는 G층
강호가 있는 곳은 S층
이제 엘리베이터를 타고 G층으로 이동한다.

강호가 탄 엘리베이터는 버튼이 2개밖에 없다
U버튼은 위로 U층을 가는 버튼, D버튼은 아래로 D층을 가는 버튼
만약 U층 위, D층 아래에 해당하는 층이 없을 때는 엘리베이터 움직이지 않음

강호가 G층에 도착하려면 버튼을 적어도 몇 번 눌러야 하는지 구하는 프로그램


*/