#include <iostream>
#include <string>
using namespace std;

int main(){
	string a,b;
	
	cin >> a >> b;
	
	int num_a = 0;
	num_a += (a[2] - '0') * 100;
	num_a += (a[1] - '0') * 10;
	num_a += (a[0] - '0');
	
	int num_b = 0;
	num_b += (b[2] - '0') * 100;
	num_b += (b[1] - '0') * 10;
	num_b += (b[0] - '0');
	
	int d = (num_a < num_b) ? num_b : num_a;
	cout << d << endl;
	return 0;
}