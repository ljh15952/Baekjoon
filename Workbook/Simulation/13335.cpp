#include <bits/stdc++.h>

using namespace std;

int n, w, L; // 트럭 수, 다리의 길이, 다리의 최대하중
int Map[105];

class Truck{
	public:
		Truck(int w_, int x_) : weight(w_), x(x_) {}
	
		int weight;
		int x;
		
		void go(){
			if(!Map[-(x+1)])
				x++;
			Map[-(x-1)] = 0;
			Map[-(x)] = 1;
		}
};

vector<Truck*> vec;

void printTruckPos(){
	for(auto it : vec){
		cout << it->x << ' ';
	}
	cout << '\n';
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> w >> L;
	
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		Map[i] = 1;
		vec.push_back(new Truck(t, -i));
	}
	
	int now_L = 0; // 현재 하중 
	int ans = 0; // 시간
	
	printTruckPos();
	for(auto it : vec){
		it->go();
	}
	printTruckPos();

	for(auto it : vec){
		it->go();
	}
	printTruckPos();

	for(auto it : vec){
		it->go();
	}
	printTruckPos();
	
	// while(!vec.empty()){
		
		
		
	// 	ans++;
	// }
	
	// cout << ans << '\n';
	
	return 0;
}

/*
w = 2

          -0 -1 -2 -3 -4
- - (- -)  -  -  -  -  -

*/