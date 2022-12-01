#include <iostream>
#include <vector>
using namespace std;

class Node{
	public:
		int num;
		int imp;
		Node Node(int n, int i){
			num = n;
			imp = i;
		}
	
};

int main(){
	
	int n,c;
	cin >> n >> c;
	
	vector<int> arr;
	vector<int> imp;
	
	for(int i = 0; i < n; ++i){
		int t;
		cin >> t;
		imp.push_back(t);
		arr.push_back(i);
	}
	
	/*
	0 1 2 3
	1 2 3 4

	*/
	
	return 0;
}

/*
Queue의 가장 앞에 있는 문서의 중요도를 확인한다.
나머지 문서들 중 현재 문서 보다 중요도 가 높은 문서가 하나라도 있다면, 이 문서를 인쇄하지 않고
Queue의 가장 뒤에 재배치 한다. 그렇지 않으면 바로 인쇄를 한다.

문서   A B C D 
중요도 2 1 4 3

Queue에 있는 문서의 수와 중요도가 주어졌을 때, 어떤 한 문서가
몇번쨰로 인쇄되는지 알아내는 것

중요도가 같은 문서가 여러 개 있을 수 있다.

*/
