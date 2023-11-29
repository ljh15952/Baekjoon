#include <iostream>

using namespace std;

int arr[10] = {3,5,1,2,4,8,7,9,6,0};
int n = 10;
	
void swap(int a, int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void print(){
	for(int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';
}