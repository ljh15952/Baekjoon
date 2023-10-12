#include <bits/stdc++.h>

using namespace std;

int N;
int arr[15];
int oper[4];

vector<int> v;

long long int min_value = 999999999999;
long long int max_value = -99999999999;

void Calculate(){
	
	long long int sum = arr[0];
	
	for(int i = 1; i <= v.size(); i++){
		if(v[i-1] == 0){
			sum += arr[i];
		}else if(v[i-1] == 1){
			sum -= arr[i];
		}else if(v[i-1] == 2){
			sum *= arr[i];
		}else if(v[i-1] == 3){
			sum /= arr[i];
		}
	}
	
	min_value = min(min_value, sum);
	max_value = max(max_value, sum);
	
}

void backTracking(){
	
	if(v.size() >= N-1){
		
		Calculate();
		return;
	}
	
	for(int i = 0; i < 4; i++){
		
		if(oper[i] > 0){
			v.push_back(i);
			oper[i]--;
			backTracking();
			v.pop_back();
			oper[i]++;
			
		}
	}
	
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	for(int i = 0; i < 4; i++){
		cin >> oper[i];
	}
	
	backTracking();
	
	cout << max_value << '\n' << min_value << '\n';
	
	return 0;
}

/*
연산자 끼워넣기

6개의 수
연산자 + 2, - 1, x 1, / 1 5개
가능한 경우의 수 60

4
1 2 3 4
1 1 1 0

1 + 2 - 3 * 4
1 + 2 * 3 - 4
1 - 2 + 3 * 4
1 - 2 * 3 + 4
1 * 2 + 3 - 4
1 * 2 + 3 - 4

*/