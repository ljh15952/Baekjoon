#include <iostream>

using namespace std;

int main(){
	
	int n;
	int num;
	int c = 0;
	
	cin >> n;
	num = n;
	while(true){
		int n1,n2;
		
		n1 = n / 10;
		n2 = n % 10;
		
		int n3 = n1 + n2;
		
		n = (n2 * 10) + (n3 % 10);
		
		c++;
		
		if(n == num)
			break;
	}
	
	cout << c;
	
	return 0;
}