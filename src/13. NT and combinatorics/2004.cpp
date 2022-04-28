#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

pair<ll, ll> PF(int n)
{
	pair<ll, ll> res;

	res.first = 0;
	res.second = 0;

	for (ll i = 2; i <= n; i *= 2)
	{
		res.first += (n / i);
	}

	for (ll i = 5; i <= n; i *= 5)
	{
		res.second += (n / i);
	}

	return res;
}

int main(){
	int n, m;
	cin >> n >> m;

	pair<ll, ll> den1 = PF(n - m), den2 = PF(m), nom = PF(n);
	ll fives = nom.second - den1.second - den2.second;
	ll twos = nom.first - den1.first - den2.first;
	cout << min(fives, twos) << '\n';
	
	return 0;
}