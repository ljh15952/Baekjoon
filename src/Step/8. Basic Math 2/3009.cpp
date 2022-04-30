#include <iostream>

using namespace std;

class Point{
public:
	int x,y;	
};

int main(){
	
	Point p1,p2,p3;
	
	cin >> p1.x >> p1.y;
	cin >> p2.x >> p2.y;
	cin >> p3.x >> p3.y;
	
	Point p;
	
	if(p1.x == p2.x){
		p.x = p3.x;
	}else if(p1.x == p3.x){
		p.x = p2.x;
	}else{
		p.x = p1.x;
	}
	
	if(p1.y == p2.y){
		p.y = p3.y;
	}else if(p1.y == p3.y){
		p.y = p2.y;
	}else{
		p.y = p1.y;
	}
	
	cout << p.x << ' ' << p.y << endl;
	
	return 0;
}