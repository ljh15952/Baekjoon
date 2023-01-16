#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	/*
	vector<int> v1(3, 5); // [5, 5, 5];
	cout << v1.size() << '\n'; // 3
	v1.push_back(7); // [5, 5, 5, 7];
	
	vector<int> v2(2); // [0, 0];
	v2.insert(v2.begin()+1 , 3); // [0, 3, 0];
	
	vector<int> v3 = {1, 2, 3, 4}; // [1, 2, 3, 4];
	v3.erase(v3.begin() + 2); //[1, 2, 4];
	
	vector<int> v4; // [];
	v4 = v3; // [1, 2, 4]; deep copy
	cout << v4[0] << v4[1] << v4[2] << '\n'; // 124
	v4.pop_back(); // [1, 2];
	v4.clear(); // []
	
	cout << v3[0] << v3[1] << '\n';
	*/
	
	/*
	vector<int> v1 = {1,2,3,4,5,6};
	
	// 1. range-based for loop
	for(int e : v1)
		cout << ++e << ' ';
	for(int& e : v1)
		cout << ++e << ' ';
	// 2. for
	for(int i = 0; i < v1.size(); i++)
		cout << v1[i] << ' ';
	
	// 3. wrong
	for(int i = 0; i <= v1.size() - 1; i++)
		cout << v1[i] << ' ';
	*/
	
	// size()메소드의 반환값이 unsigned int기 때문에 1을 빼주면
	// (unsigned int)0 - (int)1 -> overflow
	vector<int> v2;
	cout << v2.size() - 1;
	
	return 0;
}