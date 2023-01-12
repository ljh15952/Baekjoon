#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	for(int j = 0; j < 3; ++j){
		int a = 0;
		for(int i = 0; i < 4; ++i){
			int a2;
			cin >> a2;
			a += a2;
		}

		if(a == 0){
			cout << "D" << '\n';
		}else if(a == 1){
			cout << "C" << '\n';
		}else if(a == 2){
			cout << "B" << '\n';
		}else if(a == 3){
			cout << "A" << '\n';
		}else if(a == 4){
			cout << "E" << '\n';
		}
	}
	
	
	
	return 0;
}