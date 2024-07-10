#include <bits/stdc++.h>

using namespace std;

vector<string> v;
string str;
int n;

bool cmp(string& a, string& b) {

	int lenA = a.size(), lenB = b.size();
	int sumA = 0, sumB = 0;

	if (lenA != lenB) 
		return lenA < lenB;
	
	for (int i = 0; i < lenA; i++) {
		if (isdigit(a[i])) sumA += (a[i] - '0');
	}
	for (int i = 0; i < lenB; i++) {
		if (isdigit(b[i])) sumB += (b[i] - '0');
	}
	if (sumA != sumB) return sumA < sumB;

	return a < b;
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(), cmp);

	for (auto i : v)
		cout << i << '\n';

	return 0;
}