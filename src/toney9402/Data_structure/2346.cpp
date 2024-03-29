#include <iostream>
#include <deque>

using namespace std;

int main(){
 	int n;
	cin >> n;
	
	
	deque<pair<int,int>> ballons;
	
	for(int i = 1; i <= n; ++i){
		int t;
		cin >> t;
		ballons.push_back({i,t});
	}
	
	while(!ballons.empty()){
		int num = ballons.front().first;
		int mov = ballons.front().second;
		ballons.pop_front();
		cout << num << " ";
		if(mov > 0){
			for(int i = 0; i < mov-1; ++i){
				ballons.push_back(ballons.front());
				ballons.pop_front();
			}
		}else{
			for(int i = 0; i < (mov*-1); ++i){
				ballons.push_front(ballons.back());
				ballons.pop_back();
			}
		}
	}
  
 	return 0; 
}

/*
풍선 터트리기 문제

1번부터 N번까지 N개의 풍선이 원형으로 놓여있고, i번 풍선의 오른쪽에는 i+1번 풍선이 있고, 왼쪽에는 i-1번 풍선이 있다.
단 1번 풍선의 왼쪽에 N번 풍선이 있고, N번 풍선의 오른쪽에 1번 풍선이 있다.
각 풍선 안에는 종이가 하나 들어있고, 종이에는 -N보다 크거나 같고, N보다 작거나 같은 정수가 하나 적혀있다.
이 풍선들을 다음과 같은 규칙으로 터트린다.

1. 1번 풍선을 터트린다.
2. 1번 풍선 안에 있는 종이를 꺼내어 그 종이에 적혀있는 값만큼 이동하여 다음 풍선을 터트린다.
   -> 양수일시 오른쪽, 음수일시 왼쪽으로 이동한다.
3. 이미 터진 풍선은 빼고 이동한다.

ex)
1 2 3 4 5
3 2 1 -3 -1

1->4->5->3->2 순서대로 터진다.

*/
