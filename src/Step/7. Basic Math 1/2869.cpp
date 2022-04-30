#include <iostream>

using namespace std;

int main(){
	
	long long int A,B,V;
	
	cin >> A >> B >> V;

	
	int num = (V - B) / (A - B);
	
	if((V - B) % (A - B) > 0){
		num++;
	}
	
	cout << num << endl;
	
	return 0;
}
