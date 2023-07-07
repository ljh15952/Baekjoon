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

bool Backtracking(int i){
	
	for(int y = 0; y < N; y++){
		for(int x = 0; x < M; x++){
			if(setSticker(y, x, i)){
				return true;
			}
		}
	}
	
	return false;
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
			
			if(Backtracking(i)){
				break;
			}else{
				Rotate(i);
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(arr[i][j] == 1) 
				ans++;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}

// 리팩토링 좀 하자