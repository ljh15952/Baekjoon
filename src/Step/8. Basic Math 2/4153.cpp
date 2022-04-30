#include <iostream>
using namespace std;

int main(){
	
	int x,y,z;
	
	cin >> x >> y >> z;
	
	while(x+y+z != 0){
		
		int num1 = x * x;
		int num2 = y * y;
		int num3 = z * z;
		
		if(num1 == num2 + num3 || num2 == num1 + num3 || num3 == num1 + num2){
			cout << "right" << endl;
		}else{
			cout << "wrong" << endl;
		}
		
		cin >> x >> y >> z;
	}
	
	return 0;
}

