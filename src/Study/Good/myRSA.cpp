#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// 최대 공약수(GCD) 계산
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// 확장 유클리드 알고리즘을 사용하여 역 모듈로 계산
int modInverse(int a, int m) {
    int m0 = m;
    int x0 = 0, x1 = 1;

    while (a > 1) {
        int q = a / m;
        int t = m;

        m = a % m, a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}

// 소수 판별
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// RSA 키 생성
void generateRSAKeys(int& n, int& e, int& d) {
    int p, q;
    cout << "두 개의 소수 p와 q를 입력하세요: ";
    cin >> p >> q;

    if (!isPrime(p) || !isPrime(q)) {
        cout << "p와 q는 소수여야 합니다." << endl;
        return;
    }

    n = p * q;
    int phi = (p - 1) * (q - 1);

    cout << "공개 키 (n, e)를 입력하세요 (e는 phi(n)과 서로 소여야 합니다): ";
    cin >> e;

    if (gcd(e, phi) != 1) {
        cout << "e는 phi(n)과 서로 소여야 합니다." << endl;
        return;
    }

    d = modInverse(e, phi);
}

// 메시지 암호화
int encryptMessage(int message, int e, int n) {
    int ciphertext = 1;
    for (int i = 0; i < e; i++) {
        ciphertext = (ciphertext * message) % n;
    }
    return ciphertext;
}

// 메시지 복호화
int decryptMessage(int ciphertext, int d, int n) {
    int decryptedMessage = 1;
    for (int i = 0; i < d; i++) {
        decryptedMessage = (decryptedMessage * ciphertext) % n;
    }
    return decryptedMessage;
}

int main() {
    int n, e, d;
    generateRSAKeys(n, e, d);

    int message;
    cout << "암호화할 메시지(정수)를 입력하세요: ";
    cin >> message;

    // 메시지 암호화
    int ciphertext = encryptMessage(message, e, n);
    cout << "암호문: " << ciphertext << endl;

    // 메시지 복호화
    int decryptedMessage = decryptMessage(ciphertext, d, n);
    cout << "복호화된 메시지: " << decryptedMessage << endl;

    return 0;
}
