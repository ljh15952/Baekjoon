#include <iostream>
#include <string>

using namespace std;

int main(){
	
	string A,B;
	
	string score = "";
	
	cin >> A >> B;
	
	//1. 자릿수를 같게 ex 12, 1234 -> 0012 1234
	//2. string으로 계산
	//3. 출력
	
	if(A.length() > B.length()){
		int l = A.length() - B.length();
		for(int i = 0; i < l; ++i){
			B.insert(0,"0");
		}
	}else if(A.length() < B.length()){
		int l = B.length() - A.length();
		for(int i = 0; i < l; ++i){
			A.insert(0,"0");
		}
	}
	
	int length = A.length();
	int up = 0;
	for(int i = length - 1; i >= 0; --i){
		int a = A[i] - '0'; 
		int b = B[i] - '0';
		
		int c = a + b + up;
		
		up = c / 10;
		int e = c % 10;
		score += to_string(e);
	}
	if(up == 1){
		score += "1";
	}
	for(int i = score.length() - 1; i >= 0; --i){
		cout << score[i];
	}
	
	return 0;
}