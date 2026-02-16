#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
vector<string> board;

int checkMax() {
	int best = 1;

	// rows
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 1; j < N; j++) {
			if (board[i][j] == board[i][j - 1])
				cnt++;
			else
				cnt = 1;
			best = max(cnt, best);
		}
	}

	// cols
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 1; j < N; j++) {
			if (board[j][i] == board[j - 1][i])
				cnt++;
			else
				cnt = 1;
			best = max(cnt, best);
		}
	}

	return best;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	board.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	int ans = checkMax();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			// swap with right
			if (j + 1 < N && board[i][j] != board[i][j + 1]) {
				swap(board[i][j], board[i][j + 1]);
				ans = max(ans, checkMax());
				swap(board[i][j], board[i][j + 1]);
			}

			// swap with down
			if (i + 1 < N && board[i][j] != board[i + 1][j]) {
				swap(board[i][j], board[i + 1][j]);
				ans = max(ans, checkMax());
				swap(board[i][j], board[i + 1][j]);
			}

		}
	}

	cout << ans << endl;

	return 0;
}
