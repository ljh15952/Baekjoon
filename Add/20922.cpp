#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int arr[200005];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int l = 0, r = 1;
	vector<int> ct(200005, 0);
	ct[arr[l]]++;
	ct[arr[r]]++;
	int ans = 0;
	while (r < N) {
		
		if (l >= r) {
			ct[arr[++r]]++;
		}
		if (ct[arr[r]] > K) {
			ct[arr[l++]]--;
		}
		else {
			ct[arr[++r]]++;
		}
		ans = max(ans, r - l);

	}

	cout << ans << endl;
	
	return 0;
}
