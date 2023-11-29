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

int main(){
	
	
	for(int i = 1; i < n; i++){
		
		int value = arr[i];
		int j = i - 1;
		
		while(j >= 0 && arr[j] > value){
			arr[j + 1] = arr[j];
			j--;
		}
		
		arr[j + 1] = value;
		
	}
	
	print();
	
	return 0;
}

/*
삽입 정렬
배열을 정렬된 부분과 정렬되지 않은 부분으로 나눈다.
정렬이 안 된 부분의 첫번째 요소를 정렬된 부분의 적절한 위치에 삽입하여
정렬하는 과정 반복


*/