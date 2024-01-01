#include <iostream>
#include <vector>
using namespace std;

// 거스름돈을 계산하는 탐욕 알고리즘
void calculateChange(int amount) {
    // 동전의 종류와 가치
    vector<int> coins = {500, 100, 50, 10};

    cout << "Change for " << amount << " is:\n";

    for (int i = 0; i < coins.size(); ++i) {
        int numCoins = amount / coins[i];
        if (numCoins > 0) {
            cout << numCoins << " x " << coins[i] << " won\n";
            amount -= numCoins * coins[i];
        }
    }
}

int main() {
    int amount;
    cout << "Enter the amount for which you need change: ";
    cin >> amount;

    calculateChange(amount);

    return 0;
}
