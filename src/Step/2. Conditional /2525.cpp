#include<iostream>

using namespace std;

int main(){
	int h,m,t;
	
	cin >> h >> m >> t;
	
	m += t;
	if(m >= 60){
		int a = m / 60;
		h += a;
		
		m %= 60;
		h %= 24;
	}
	
	cout << h << " " << m << endl;
	
	return 0;
}