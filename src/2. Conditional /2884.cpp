#include <iostream>

using namespace std;

int main(){
	int h,m; //hour minute
	
	cin >> h >> m;
	if(m - 45 >= 0){
		m -= 45;
	}else{
		m = 60 + (m - 45);
		if(h - 1 < 0){
			h = 24 + (h - 1); 
		}else{
			h -= 1;
		}
	}
	
	cout << h << " " << m << endl;
	return 0;
}