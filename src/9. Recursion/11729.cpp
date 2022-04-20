#include <iostream>

using namespace std;

void hanoi(int n, int start, int mid, int to){
	if(n == 1){
		printf("%d %d\n", start, to);
		return;
	}
	
	hanoi(n - 1, start, to, mid);
	
	printf("%d %d\n",start,to);
	
	hanoi(n - 1, mid, start, to);
	
}

int main(){
	
	int n;
	
	cin >> n;
	cout << (1 << n) - 1 << endl;
	hanoi(n,1,2,3);
	
	return 0;
}