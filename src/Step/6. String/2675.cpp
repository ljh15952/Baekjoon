#include<iostream>
#include<string>
using namespace std;

int main(){

	int n;
	cin >> n;
	
	
	for(int i = 0; i < n; ++i){
		int size;
		cin >> size;
		char str[20];
		scanf("%s",str);
		string s;
		int index = 0;
		while(str[index] != '\0'){
			for(int k = 0; k < size; ++k){
				s += str[index];
			}
			index++;
		}

		cout << s << endl;
	}
	return 0;
}