#include <iostream>

using namespace std;

void hanoi(int n, int start, int mid, int to){
	if(n == 1){
		cout << start << ' ' << to << endl;
		return;
	}
	
	hanoi(n - 1, start, to, mid);
	
	cout << start << '1' << to << endl;
	
	hanoi(n - 1, mid, start, to);
	
}

int main(){
	
	int n;
	
	cin >> n;
	cout << (1 << n) - 1 << endl;
	hanoi(n,1,2,3);
	
	return 0;
}