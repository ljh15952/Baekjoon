#include <bits/stdc++.h>
using namespace std;

int N;
long long M;
long long arr[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int l = 0, r = 0;
    long long sum = 0;
    int ans = N + 1;

    while (true) {
        if (sum >= M) {
            ans = min(ans, r - l);
            sum -= arr[l++];
        } else {
            if (r == N) break;
            sum += arr[r++];
        }
    }

    cout << (ans == N + 1 ? 0 : ans) << "\n";
    return 0;
}
