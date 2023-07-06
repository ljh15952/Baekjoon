#include <bits/stdc++.h>

using namespace std;

int N, M;
int K; // 스티커의 개수
int R, C; // 행 열

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

void Rotate(){
	
	int r = vec[1]->row;
	int c = vec[1]->col;
	
	int tempArr[15][15] = {0,};
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			tempArr[j][r - i - 1] = vec[1]->val[i][j];
		}
	}
	
	cout << vec[1]->row << ' ' << vec[1]->col << '\n';
	swap(vec[1]->row, vec[1]->col);
	cout << vec[1]->row << ' ' << vec[1]->col << '\n';
	
	cout << '\n';
	for(int i = 0; i < vec[1]->row; i++){
		for(int j = 0; j < vec[1]->col; j++){
			cout << tempArr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
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
	
	cout << '\n';
	for(int i = 0; i < vec[1]->row; i++){
		for(int j = 0; j < vec[1]->col; j++){
			cout << vec[1]->val[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	
	Rotate();
	
	
	
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