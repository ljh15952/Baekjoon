#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point{
	public:
		int x,y;
		Point(int _x,int _y) : x(_x) , y(_y) {};
};

bool Compare(Point &a, Point &b){
	if(a.y == b.y){
		return a.x < b.x;
	}else{
		return a.y < b.y;
	}
}

int main(){
	
	int n;
	cin >> n;
	
	int x,y;
	
	vector<Point> arr;
	
	for(int i = 0; i < n; i++){
		scanf("%d %d",&x,&y);
		arr.push_back(Point(x,y));
	}
	
	sort(arr.begin(),arr.end(),Compare);
	
	for(int i = 0; i < n; i++){
		cout << arr[i].x << ' ' << arr[i].y << '\n';
	}
	
	return 0;
}