#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Person{
	public:
		Person(string s,int k,int e,int m) : name(s), kor(k), eng(e), math(m) {};
		string name;
		int kor;
		int eng;	
		int math;
};

bool Compare(Person p1, Person p2){
	if(p1.kor != p2.kor){
		return p1.kor > p2.kor;
	}else if(p1.eng != p2.eng){
		return p1.eng < p2.eng;
	}else if(p1.math != p2.math){
		return p1.math > p2.math;
	}else{
		return p1.name < p2.name;
	}
	
	
}

int main(){
	
	int N;
	cin >> N;
	
	
	string s;
	int k,e,m;
	vector<Person> v;
	for(int i = 0; i < N; ++i){
		cin >> s >> k >> e >> m;
		v.push_back(Person(s,k,e,m));
	}
	
	sort(v.begin(),v.end(),Compare);
	
	for(Person p : v){
		cout << p.name << "\n";
	}
	
	return 0;
}