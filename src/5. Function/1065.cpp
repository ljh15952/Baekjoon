#include <iostream>

using namespace std;
bool isHansu(int n){
	int a,b;
	a = n % 10;
	n /= 10;
	b = n % 10;
	n /= 10;
	
	int diff = b - a;
	
	while(n != 0){
		a = n % 10;
		n /= 10;
		if(b + diff == a){
			b = a;
		}else{
			return false;
		}
		
	}
	return true;
}
int main(){
	int n;
	
	scanf("%d",&n);
	int sum = 0;
	for(int i = 1; i <= n; i++){
		if(isHansu(i)){
			sum++;
		}
	}
	cout << sum << endl;
	
	return 0;
}