#include <bits/stdc++.h>

using namespace std;


int A[1000005], B[1000005];

int arr[2000005];

int main()
{

	ios::sync_with_stdio(0); cin.tie(0);
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	int AIdx = 0, BIdx = 0;
	int n = 0;

	while (AIdx < N || BIdx < M) {
		if (AIdx >= N) {
			while (BIdx < M)
				arr[n++] = B[BIdx++];
		}
		else if (BIdx >= M) {
			while (AIdx < N)
				arr[n++] = A[AIdx++];
		}
		else {
			if (A[AIdx] < B[BIdx])
				arr[n++] = A[AIdx++];
			else
				arr[n++] = B[BIdx++];
		}
	}

	for (int i = 0; i < N + M; i++)
		cout << arr[i] << ' ';
	cout << '\n';

	return 0;
}
