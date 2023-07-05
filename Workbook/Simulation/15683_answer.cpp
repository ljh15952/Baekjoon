
#include <bits/stdc++.h>

using namespace std;

int main() {
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	
	// 4진수
	for(int tmp = 0; tmp < 64; tmp++){
	    int brute = tmp;
	    cout << tmp << " : ";
	    for(int i = 0; i < 3; i++){
	        cout << brute % 4;
	        brute /= 4;
	    }
	    cout << '\n';
	}
    
	
	return 0;
}
