#include <iostream>
#include <vector>
using namespace std;

template<typename T>
T maxVal(T a, T b) {
    return (a > b) ? a : b;
}

int knapsack(vector<int>& values, vector<int>& weights, int capacity, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = maxVal(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n; // 물건의 수
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> values(n);
    vector<int> weights(n);

    cout << "Enter the values of items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    cout << "Enter the weights of items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    int capacity; // 배낭의 용량
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int result = knapsack(values, weights, capacity, n);

    cout << "Maximum value that can be obtained: " << result << endl;

    return 0;
}