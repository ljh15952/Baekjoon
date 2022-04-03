#include<iostream>

using namespace std;

int main(){
	int d1,d2,d3;
	int money = 0;
	cin >> d1 >> d2 >> d3;
	
	if(d1 == d2 && d2 == d3){
		money = 10000 + (d1 * 1000);
	}else if(d1 == d2){
		money = 1000 + (d1 * 100);
	}else if(d2 == d3){
		money = 1000 + (d2 * 100);
	}else if(d1 == d3){
		money = 1000 + (d3 * 100);
	}else{
		int max = (d1 >= d2 && d1 >= d3) ? d1 :
		(d2 >= d1 && d2 >= d3) ? d2 : d3;
		money = (max * 100);
	}
	
	cout << money << endl;
	return 0;
}