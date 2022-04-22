#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Person{
	public:
		int age;
		string name;
		Person(int a, string n) : age(a), name(n) {};
};

bool compare(Person p1, Person p2){
	return	p1.age < p2.age;
}

int main(){
	
	int n;
	
	cin >> n;
	int age;
	string name;
	vector<Person> arr;
	for(int i = 0; i < n; i++){
		cin >> age >> name;
		arr.push_back(Person(age,name));
	}
	
	stable_sort(arr.begin(),arr.end(),compare);
	
	for(Person p : arr){
		cout << p.age << ' ' << p.name << '\n';
	}
	
	return 0;
}