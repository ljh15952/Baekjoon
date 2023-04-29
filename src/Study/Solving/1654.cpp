#include <bits/stdc++.h>

using namespace std;

int K, N; // 이미 가지고 있는 랜선의 수 K
			// 필요한 랜선의 개수 N K <= N
int lens[10001];

long long int lo;
long long int hi;
long long int mid;


int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> K >> N;
	
	for(int i = 0; i < K; ++i)	cin >> lens[i];
	
	lo = 1;
	hi = *max_element(lens, lens+K);
	
	int max = 0;
	
	while(lo <= hi){
		mid = (lo + hi) / 2;
		
		int sum = 0;
		for(int i = 0; i < K; ++i){
			sum += lens[i] / mid;
		}
		
		if(sum >= N){
			lo = mid + 1;
			if(mid > max) max = mid;
		}else{
			hi = mid - 1;
		}
	}
	
	cout << max << '\n';
	
	return 0;
}