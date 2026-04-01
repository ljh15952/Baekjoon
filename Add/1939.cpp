#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, int>> graph[10001];

bool canMove(int start, int dest, int weight) {

	vector<bool> visited(N + 1, false);
	queue<int> q;

	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == dest) return true;

		for (auto &next : graph[cur]) {
			int nxt = next.first;
			int limit = next.second;

			if (!visited[nxt] && limit >= weight) {
				visited[nxt] = true;
				q.push(nxt);
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	int low = 1, high = 0;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });

		high = max(high, c);
	}

	int start, dest;
	cin >> start >> dest;

	int answer = 0;

	while (low <= high) {
		int mid = low + (high - low) / 2; //

		if (canMove(start, dest, mid)) {
			answer = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	cout << answer << '\n';

	return 0;
}
