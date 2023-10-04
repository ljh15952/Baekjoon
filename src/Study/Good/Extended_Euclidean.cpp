#include <iostream>

using namespace std;

void EEA(int a, int b){
	int r1 = a, r2 = b;
	int s1 = 1, s2 = 0;
	int t1 = 0, t2 = 1;
	
	int q, r, s, t;
	
	while(1){
		
		q = r1 / r2;
		r = r1 - (q * r2);
		s = s1 - (q * s2);
		t = t1 - (q * t2);
		
		if(r == 0){
			cout << "GCD : " << r2 << '\n';
			cout << "S : " << s2 << '\n';
			cout << "T : " << t2 << '\n';
			break;
		}
		
		r1 = r2;
		r2 = r;
		s1 = s2;
		s2 = s;
		t1 = t2;
		t2 = t;
		
	}
}

int main(){
	
	EEA(12, 5);	
	
	return 0;
}