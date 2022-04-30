#include <iostream>
#include <string>
using namespace std;

int main(){
	
	string str;
	cin >> str;
	for(int i = 0; i < str.length(); ++i){
		str[i] = toupper(str[i]);

	}
	
	int alpha[26] = {0,};
	
	for(int i = 0; i < str.length(); ++i){
		alpha[str[i] - 65]++;
	}
	
	int max = alpha[0];
	int max_num = 0;
	for(int i = 1; i < 26; ++i){
		if(max < alpha[i]){
			max = alpha[i];
			max_num = i;
		}
	}

	for(int i = 0; i < 26; ++i){
		if(max == alpha[i] && max_num != i){
			cout << "?" << endl;
			return 0;
		}
	}
	printf("%c\n",max_num + 65);
	return 0;
}