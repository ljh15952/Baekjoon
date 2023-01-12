#include<bits/stdc++.h>

using namespace std;

int num[9], result[7];

int main(){
	
	int a;
	for(int i = 0; i < 9; ++i) cin >> num[i];

	
	for(int a = 0; a < 9; ++a){
		for(int b = a + 1; b < 9; ++b){
			int sum = 0, idx = 0;
			for(int c = 0; c < 9; ++c){
				if(c != a && c != b){
					sum += num[c];
					result[idx++] = num[c];
				}
			}
			
			if(sum == 100){
				sort(result,result+7);
				for(int i = 0; i < 7; ++i){
					cout << result[i] << "\n";
				}
				return 0;
			}
			
		}
	}
	
	/*
	9명의 난쟁이들
	일곱 난쟁이의 키의 합이 100이 됨
	일곱 난쟁이의 키를 오름차순 출력
	*/
	
	return 0;
}