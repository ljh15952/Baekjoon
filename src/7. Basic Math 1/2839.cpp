#include <iostream>

using namespace std;

int main(){
	
	int n;
	
	cin >> n;
	int num = 0;
	while(n > 0){
		if(n % 5 == 0){
			n -= 5;
			num++;
		}else if(n % 3 == 0){
			n -= 3;
			num++;
		}else if(n > 5){
			n -= 5;
			num++;
		}else{
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << num << endl;
	return 0;
}