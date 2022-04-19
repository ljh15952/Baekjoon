#include <iostream>

using namespace std;

//width height
void star(int n, int w, int h){
	if((w / n) % 3 == 1 && (h / n) % 3 == 1){
		cout << ' ';
	}
	else if(n == 1){
		cout << '*';
	}
	else{
		star(n/3,w,h);
	}
}


int main(){
	
	int n;
	
	cin >> n;
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			star(n,i,j);
		}
		cout << endl;
	}
	
	
	return 0;
}