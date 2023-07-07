#include <bits/stdc++.h>

using namespace std;

int N, M;
int K; // 스티커의 개수
int R, C; // 행 열

int arr[45][45];

class Sticker{
	public:
		Sticker(int r,int c){
			row = r;
			col = c;
		}
		int row;
		int col;
		int val[15][15] = {0,};	
};

vector<Sticker*> vec;

void swap(int &x, int &y){
	int tmp = x;
	x = y;
	y = tmp;
}

void Rotate(int k){
	
	int r = vec[k]->row;
	int c = vec[k]->col;
	
	int tempArr[15][15] = {0,};
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			tempArr[j][r - i - 1] = vec[k]->val[i][j];
		}
	}
	
	swap(vec[k]->row, vec[k]->col);
	
	for(int i = 0; i < vec[k]->row; i++){
		for(int j = 0; j < vec[k]->col; j++){
			vec[k]->val[i][j] = tempArr[i][j];
		}
	}
}

bool setSticker(int y, int x, int k){
	
	for(int i = 0; i < vec[k]->row; i++){
		for(int j = 0; j < vec[k]->col; j++){
			if(y + i >= N || x + j >= M){
				return false;
			}
			if(vec[k]->val[i][j] == 1 && arr[y + i][x + j] == 1){
				// 놓을 수 없음 돌려야 함
				return false;
			}
		}
	}
	
	// 놓을 수 있음!
	for(int i = 0; i < vec[k]->row; i++){
		for(int j = 0; j < vec[k]->col; j++){
			if(vec[k]->val[i][j] == 0){
				continue;
			}
			arr[y+i][x+j] = vec[k]->val[i][j];
		}
	}
	
	return true;
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M >> K;
	
	for(int i = 0; i < K; i++){
		cin >> R >> C;
		Sticker *s = new Sticker(R,C);
		vec.push_back(s);
		for(int r = 0; r < R; r++){
			for(int c = 0; c < C; c++){
				cin >> s->val[r][c];
			}
		}
	}
	
	for(int i = 0; i < K; i++){
		for(int j = 0; j < 4; j++){
			
			bool flag = false;
			for(int y = 0; y < N; y++){
				for(int x = 0; x < M; x++){
					
					flag = setSticker(y, x, i);
					
					if(flag){
						break;
					}
				}
				if(flag){
					break;
				}
			}
			
			if(flag){
				break;
			}else{
				Rotate(i);
			}
		}
		
		// cout << i << '\n';
		// for(int i = 0; i < N; i++){
		// 	for(int j = 0; j < M; j++){
		// 		cout << arr[i][j] << ' ';
		// 	}
		// 	cout << '\n';
		// }
		// cout << '\n';
	}
	
	int ans = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(arr[i][j] == 1) 
				ans++;
		}
	}
	
	cout << ans << '\n';
	
	/*
	1. 입력 받기
	2. 각 스티커 90도 회전하기(row,col 바뀜)
	3. 차례대로 노트북 배열에 배치하기
	4. 회전해서 노트북에 배치하기
	5. 
	
	*/
	
	return 0;
}

/*
스티커 붙이기

스티커들을 많이 받았다.
스티커는 아래와 같이 사각 모눈종이 위에
인쇄되어 있으며, 스티커의 각 칸은 상하좌우로 모두 연결되어 있다.
모눈종이의 크기는 스티커의 크기에 꼭 맞아서
상하좌우에 스티커가 포함되지 않는 불필요한 행이나 열이 존재X

스티커를 붙이는 방법
1. 스티커를 회전시키지 않고 모눈종이에서 때어낸다.
2. 다른 스티커와 겹치거나 노트북을 벗어나지 않으면서
	스티커를 붙일 수 있는 위치를 찾는다.
	노트북의 위쪽부터 스티커를 채워나가려고 해서
	스티컬르 붙일 수 있는 위치가 여러 곳 있다면
	가장 위쪽의 위치를 선택한다.
	가장 위쪽에 해당하는 위치도 여려 곳이 있다면 
	그중에서 가장 왼쪽의 위치를 선택
3. 선택한 위치에 스티커를 붙인다. 만약 스티커를 붙일 수 있는 
	위치가 전혀 없어서 스티커를 붙이지 못했다면, 스티커를
	시계 방향으로 90도 회전한 뒤 2번 과정을 반복한다.
4. 위의 과정을 네 번 반복해서 스티커를 0도, 90도, 180도, 270도
	회전시켜 봤음에도 스티커를 붙이지 못했다면 해당 스티커를 붙이지
	않고 버린다.

스티커를 차례대로 붙이고 난 후 노트북에서
몇 개의 칸이 채워졌는지 구해보자

*/