#include <iostream>

using namespace std;

int main(){
	
	long long int n;
	
	cin >> n;
	
	/*
	1칸->6칸->12칸->18칸->24칸->30칸... 
	1 1칸 :1
	2 6칸 : 2~7
	3 12칸 : 8~19
	4 18칸 : 20~37
	5 24칸 : 38~61
	.
	.
	규칙이 있다.
	*/
	if(n == 1){
		cout << "1" << endl;
		return 0;
	}
	int i = 1;
	int plusNum = 6;
	int sum = 1;

	while(n > i){
		i += plusNum;
		plusNum += 6;
		sum++;
	}
	
	cout << sum << endl;
	return 0;
}