#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point{
	public:
		int x,y;
		Point(int _x,int _y) : x(_x), y(_y) {};
};

bool compare(Point &a, Point &b){
	if(a.x == b.x){
		return a.y < b.y;
	}
	return a.x < b.x;
}

int main(){

	int n;
	
	cin >> n;
	
	vector<Point> arr;
	int x,y;	
	for(int i = 0; i < n; i++){
		scanf("%d %d",&x, &y);
		arr.push_back(Point(x,y));
	}
	
	sort(arr.begin(),arr.end(),compare);
			
	
	for(int i = 0; i < n; i++){
		cout << arr[i].x << ' ' << arr[i].y << '\n';
	}
	
	return 0;
}