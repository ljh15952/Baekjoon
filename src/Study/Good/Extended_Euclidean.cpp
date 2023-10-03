#include <iostream>

using namespace std;

void EEA(int a, int b){
	int r0 = a, r1 = b;
	int s0 = 1, s1 = 0;
	int t0 = 0, t1 = 1;
	int temp = 0, q = 0;
	
	while(r1){
		q = r0 / r1; // 4 = 72 / 17
		temp = r0; // temp = 72
		r0 = r1; // r0 = 17
		r1 = temp - r1 * q; // r1 = 72 - 17 * 4 (4)
		temp = s0; // temp = 1
		s0 = s1; // s0 = 0
		s1 = temp - s1 * q; // s1 = 1 - 0 * 4
		temp = t0; // temp = 0
		t1 = temp - t1 * q;
	}
}