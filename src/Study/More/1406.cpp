#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
		
	string str;
	cin >> str;
	
	int n;
	cin >> n;
	
	int cursor = str.length();
	
	for(int i = 0 ; i < n; ++i){
		char c;
		cin >> c;
		if(c == 'L'){
			cursor = max(0, cursor-1);
		}else if(c == 'D'){
			int leng = str.length();
			cursor = min(leng, cursor+1);
		}else if(c == 'B'){
			if(cursor > 0){
				str.erase(str.begin()+cursor-1);
				cursor--;
			}
		}else if(c == 'P'){
			string s;
			cin >> s;
			str.insert(cursor,s);
			cursor++;
		}
	}
	//ㅈ빠지게 했더니 시간 초과 뜨네"?
	cout << str << endl;
	
	return 0;
}