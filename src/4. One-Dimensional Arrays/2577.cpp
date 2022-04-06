#include <iostream>
#include <string>
using namespace std;

int main(){
	int a,b,c;
	
	cin >> a >> b >> c;
	
	int num = a * b * c;
	
	//more good code
	//string s = to_string(num);
	int arr[10]={0,};
	
	while(num>0){
		arr[num % 10]++;
		num /= 10;
		//arr[s[i] - '0']++;
	}
	
	
	for(int i = 0; i < 10; i++){
		cout << arr[i] << endl;
	}
	return 0;
}