#include <iostream>
#define PI 3.1415926535897932

using namespace std;

int main(){
	
	double n;
	cin >> n;
	
	cout << fixed;
	cout.precision(6);
	
	cout << n * n * PI << endl;
	cout << n * n * 2 << endl;
	return 0;
}