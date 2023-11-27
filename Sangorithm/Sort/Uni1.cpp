#include <bits/stdc++.h>

using namespace std;

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	int a[10] = {1,2,3,4,11,6,7,8,9,10};
	
	int n = 10;
	
	for(int i = 1; i < n; i++){
		
		int j = i - 1;
		int v = a[i];
		
		while(j >= 0 && v < a[j]){
			a[j+1] = a[j];
			j--;
		}
		
		a[j+1] = v;
	}
	
	for(int i = 0; i < n; i++){
		cout << a[i] << ' ';
	}
	
	return 0;
}