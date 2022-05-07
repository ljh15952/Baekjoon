#include <iostream>
#include <math.h>
using namespace std;

// 시간초과
// int getScore(int dis){
// 	int sum = 0;
// 	int plus = 1;
// 	int ct = 0;
// 	while(true){
// 		for(int i = 0; i < 2; ++i){
// 			sum += plus;
// 			ct++;
// 			if(sum >= dis){
// 				return ct;
// 			}
// 		}
// 		plus++;
// 	}
// }

int main(){
	
	int t;
	scanf("%d",&t);
	
	for(int j = 0; j < t; ++j){
		int x,y;
		scanf("%d %d",&x,&y);
		int length = y - x;

		int d = sqrt(length);
		int move_count = 0;
		
		pow(d, 2) == length ? move_count = 2 * d - 1 : move_count = 2 * d; // 2. 제곱 수 case
        if (length > d * (d + 1)) 
			move_count += 1; // 3. 중간 값 case
        printf("%d\n", move_count);
	}
	
	return 0;
}