#include <iostream>

using namespace std;

int search(int n){
	return 0;
}

int arr[100];

int main(){
	
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	
	int num;
	cout << "i want to find num : ";
	cin >> num;
	
	for(int i = 0; i < n; ++i){
		cout << arr[i] << endl;	
	}
	
	cout << "goal is : " << num << endl;
	
	return 0;
}

/*
5
4 1 5 2 3
*/