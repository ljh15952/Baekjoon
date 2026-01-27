#include <iostream>

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n) {
		int r = 0;
		int len = 0;

		while (1) {
			r = (r * 10 + 1) % n;
			len++;
			if (r == 0) {
				cout << len << "\n";
				break;
			}
		}
	}

	return 0;
}

