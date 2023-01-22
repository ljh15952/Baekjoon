#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	list<char> str;
	
	for(auto it : s){
		str.push_back(it);
	}
	
	list<char>::iterator cursor = str.end();
	
	int M;
	cin >> M;
	while(M--){
		char c;
		cin >> c;
		if(c == 'L'){
			if(cursor != str.begin()) 
				cursor--;
		}else if(c == 'D'){
			if(cursor != str.end()) 
				cursor++;
		}else if(c == 'B'){
			if(cursor != str.begin()){
				cursor--;
				cursor = str.erase(cursor);
			}
		}else if(c == 'P'){
			char c2;
			cin >> c2;
			str.insert(cursor, c2);
		}
	}
	

	
	for(auto it : str){
		cout << it;
	}
	
	
	
	return 0;
}