#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
  cin >> n;
	for (int i = 0; i < n; i++) {
		list<char> li;
		list<char>::iterator cursor = li.begin();
		string s;
		cin >> s;
		
		for(char it : s){
			if(it == '<'){
				if(cursor != li.begin()) cursor--;
			}else if(it == '>'){
				if(cursor != li.end()) cursor++;
			}else if(it == '-'){
				if(cursor != li.begin()){
					cursor--;
					cursor = li.erase(cursor);
				}
			}else{
				li.insert(cursor,it);
			}
		}

		for(auto it : li){
			cout << it;
		}
		cout << '\n';
	}
	return 0;
}
