#include <iostream>

using namespace std;

int main(){
	
	int arr[1000001]={1,1,1,0,};
	arr[1] = 1;
	
	for(int i = 2; i <= 1000000; ++i){
		for(int j = 2; j * i <= 1000000; ++j){
			arr[i*j] = 1;
		}
	}
	
	cin.tie(NULL);
 	ios_base::sync_with_stdio(0);
	
	int n,left,right;
	
	while(1){
		cin >> n;
		if(!n) break;
		
		left = 3;
		right = n - 3;
		
		while(left <= right){
			if(!arr[left] && !arr[right]){
				if(left + right == n)
					break;
			}
			left += 2;
			right -= 2;
		}
		
		if(left>right)  
			cout<<"Goldbach's conjecture is wrong.";
    	else 
			cout<<n<<" = "<<left<<" + "<<right<<'\n';
	}
	
	return 0;
}