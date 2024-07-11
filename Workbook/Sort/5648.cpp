#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> vec;

bool cmp(string& a, string& b) {
	long long int _a = stoll(a);
	long long int _b = stoll(b);
	return _a < _b;
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		reverse(s.begin(), s.end());
		vec.push_back(s);
	}

	for (int j = 0; j < vec.size(); j++) {
		for (int i = 0; i < vec[j].length(); i++) {
			if (vec[j][i] != '0') {
				vec[j].erase(0, i);
				break;
			}
		}
	}

	sort(vec.begin(), vec.end(), cmp);

	for (auto v : vec) {
		cout << v << '\n';
	}

	return 0;
}