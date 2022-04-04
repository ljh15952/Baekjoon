#include <iostream>

using namespace std;

int main(){
	
	int max = -99999;
	int num = 0;
	for(int i = 0; i < 9; i++)
	{
		int n;
		cin >> n;
		if(n > max){
			max = n;
			num = i+1;
		}
	}
	
	cout << max << endl;
	cout << num << endl;
	
	
	
	return 0;
}