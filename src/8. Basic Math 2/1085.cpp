#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	
	int x,y,w,h;
	
	cin >> x >> y >> w >> h;
	
	vector<int> arr;
	arr.push_back(abs(0 - x));
	arr.push_back(abs(0 - y));
	arr.push_back(w - x);
	arr.push_back(h - y);

	cout << *min_element(arr.begin(),arr.end()) << endl;;
	
	return 0;
}