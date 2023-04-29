#include <bits/stdc++.h>

using namespace std;

long long int N, M; // 나무의 수, 나무의 길이
int trees[1000000];

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; ++i)	cin >> trees[i];
	sort(trees, trees + N);
	
	long long int lo = 0, hi = trees[N-1];
	long long int sum = 0;
	long long int cut = 0;
	long long int Max = -1;
	while(lo <= hi){
		sum = 0;
		cut = (lo + hi) / 2;
		
		for(int i = 0; i < N; ++i){
			if(trees[i] - cut > 0)
				sum += trees[i] - cut;
		}
		
		if(sum >= M){
			lo = cut + 1;
			if(cut > Max)
				Max = cut;
		}else{
			hi = cut - 1;
		}
	}
	
	cout << Max << '\n';
	
	return 0;
}