#include <bits/stdc++.h>

using namespace std;

int n, w, L; // 트럭 수, 다리의 길이, 다리의 최대하중
int ans;
int bridge[105];
queue<int> truck;


bool isEmpty(){
	for(int i = 0; i < w; i++)
		if(bridge[i]) return false;
	return true;
}

void go(){
	for(int i = w-1; i > 0; i--)
		bridge[i] = bridge[i - 1];
	bridge[0] = 0;
}

int calculate(){
	int sum = 0;
	for(int i = 0; i < w; i++)
		sum += bridge[i];
	return sum;
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> w >> L;
	
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		truck.push(t);
	}
	
	do{
		int tmp = calculate();
		if(tmp <= L){
			tmp -= bridge[w-1];
			go();
			
			if(!truck.empty() && (tmp+truck.front() <= L)){
				bridge[0] = truck.front();
				truck.pop();
			}
		}
		ans++;
	}while(!isEmpty());

	cout << ans << '\n';
	
	return 0;
}

/*
w = 2

          -0 -1 -2 -3 -4
- - (- -)  -  -  -  -  -

*/