#include <bits/stdc++.h>

using namespace std;

int main(){
	
	list<int> L = {1,2};
	list<int>::iterator t = L.begin(); // t는 1을 가르키는 중
	L.push_front(10); // 10 1 2
	
	cout << *t << '\n'; // 1출력
	
	L.push_back(5); // 10 1 2 5
	L.insert(t, 6); // t가 가리키는 곳 앞에 6을 삽입 10 6 1 2 5
	t++; // t를 1칸 앞으로 전진, t는 2를 가르킴
	t = L.erase(t); // t가 가르키는 값을 제거
									// 그 다음 원소인 5의 위치를 반환
									// 10 6 1 5 , t = 5
	
	cout << *t << '\n';
	for(auto it : L) cout << it << ' ';
	cout << '\n';
	for(list<int>::iterator it = L.begin(); it != L.end(); ++it){
		cout << *it << ' ';
	}
	return 0;
}
