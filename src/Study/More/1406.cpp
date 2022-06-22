#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(){
		
	string str;
	cin >> str;
	
	int n;
	cin >> n;
	
	list<char> l(str.begin(),str.end());
	
	auto cursor = l.end();
	
	for(int i = 0 ; i < n; ++i){
		char c;
		cin >> c;
		if(c == 'L'){
			if(cursor != l.begin()){
				cursor--;
			}
		}else if(c == 'D'){
			if(cursor != l.end()){
				cursor++;
			}
		}else if(c == 'B'){
			if(cursor != l.begin()){
				cursor = l.erase(--cursor);
			}
		}else if(c == 'P'){
			char s;
			cin >> s;
			l.insert(cursor,s);
		}
	}
	
	for(auto it = l.begin(); it != l.end(); it++){
		cout << *it;
	}
	
	return 0;
}