#include <iostream>

using namespace std;

int E, S, M;
int e = 1, s = 1, m = 1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> E >> S >> M;

	for (int i = 1; i <= 7980; i++) {

		if (e == E && s == S && m == M) {
			cout << i << endl;
			return 0;
		}

		e = e % 15 + 1;
		s = s % 28 + 1;
		m = m % 19 + 1;
	}

	return 0;
}
