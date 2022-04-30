#include <iostream>

using namespace std;

int main(){
	
	int t;
	
	cin >> t;
	
	//6 12 10 -> 402
	//층 방수 몇번째 손님
	for(int i = 0; i < t; i++){
		int H,W,N;

		cin >> H >> W >> N;
		if(N % H == 0){
			int first = H;
			int last = N / H;
			printf("%d%02d\n",first,last);
		}
		else{
			int first = N % H;
			int last = N / H + 1;
			printf("%d%02d\n",first,last);
		}
	}
	

	
		
	return 0;
}