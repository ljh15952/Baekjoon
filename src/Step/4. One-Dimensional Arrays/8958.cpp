#include <iostream>
#include <string>
using namespace std;

int main(){
	
	int n;
	
	scanf("%d",&n);
	
	string arr[n];
	
	for(int i = 0; i < n; i++){
		char s[80];
		scanf("%s",s);
		arr[i] = s;
	}
	int upScore = 1;
	int score[n] = {0,};
	for(int i = 0; i < n; i++){
		upScore = 1;
		for(int j = 0; j < arr[i].length(); j++){
			if(arr[i][j] == 'O'){
				score[i] += upScore;
				upScore++;
			}else{
				upScore = 1;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		cout << score[i] << endl;
	}
	return 0;
}