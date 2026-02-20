#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int K;
vector<char> signv;
bool usedDigit[10];

bool ok(int a, int b, char s) {
	if (s == '<') 
		return a < b;
	return a > b;
}

bool dfs(int pos, string &cur, const vector<int> &order, string &ans) {
	
	if (pos == K + 1) {
		ans = cur;
		return true;
	}

	for (int d : order) {
		if (usedDigit[d]) 
			continue;

		if (pos > 0) {
			int prev = cur[pos - 1] - '0';
			if (!ok(prev, d, signv[pos - 1]))
				continue;
		}

		usedDigit[d] = true;
		cur.push_back(char('0' + d));

		if (dfs(pos + 1, cur, order, ans))
			return true;

		cur.pop_back();
		usedDigit[d] = false;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> K;
	signv.resize(K);
	for (int i = 0; i < K; i++) cin >> signv[i];

	vector<int> asc, desc;
	for (int i = 0; i <= 9; i++) asc.push_back(i);
	for (int i = 9; i >= 0; i--) desc.push_back(i);

	string minAns, maxAns, cur;
	memset(usedDigit, 0, sizeof(usedDigit));
	cur.clear();
	dfs(0, cur, asc, minAns);

	memset(usedDigit, 0, sizeof(usedDigit));
	cur.clear();
	dfs(0, cur, desc, maxAns);

	cout << maxAns << "\n" << minAns << "\n";

	return 0;
}
