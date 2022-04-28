#include <iostream>
#include <algorithm>

using namespace std;



pair<long long int, long long int> PF(int n)
{
	pair<long long int, long long int> res;

	res.first = 0;
	res.second = 0;

	for (long long int i = 2; i <= n; i *= 2)
	{
		res.first += (n / i);
	}

	for (long long int i = 5; i <= n; i *= 5)
	{
		res.second += (n / i);
	}

	return res;
}

int main(){
	int n, m;
	cin >> n >> m;

	pair<long long int, long long int> den1 = PF(n - m), den2 = PF(m), nom = PF(n);
	long long int fives = nom.second - den1.second - den2.second;
	long long int twos = nom.first - den1.first - den2.first;
	cout << min(fives, twos) << '\n';
	
	return 0;
}