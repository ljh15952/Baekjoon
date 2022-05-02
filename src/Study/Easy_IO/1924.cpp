#include <iostream>
#include <string>
using namespace std;

int main(){
	
	int x,y;
	string day[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
	int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	//월 요일
	cin >> x >> y;
	
	int d = y;
	
	for(int i = 0; i < x - 1; ++i){
		d += month[i];
	}

	cout << day[d%7] << endl;
	
	return 0;
}