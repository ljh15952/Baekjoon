#include <iostream>

using namespace std;

int arr[8] = {24,75,92,83,61,48,97,50};
int n = sizeof(arr) / sizeof(arr[0]);

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int low, int high) {
    int pivot = arr[high]; // 피벗을 배열의 마지막 요소로 선택
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // 현재 요소가 피벗보다 작으면 교환
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // 피벗의 위치를 교환하여 피벗을 정렬된 위치로 이동
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int low, int high) {
    if (low < high) {
        // 배열을 분할하고 피벗을 얻음
        int pivotIndex = partition(low, high);

        // 피벗을 기준으로 두 부분을 각각 정렬
        quickSort(low, pivotIndex - 1);
        quickSort(pivotIndex + 1, high);
    }
}


int main(){
	
	cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
	
	quickSort(0, n - 1);
	
	cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
	
	return 0;
}