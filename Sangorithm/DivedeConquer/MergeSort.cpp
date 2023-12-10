#include <iostream>

using namespace std;

int arr[8] = {24,75,92,83,61,48,97,50};
int n = sizeof(arr) / sizeof(arr[0]);


void merge(int low, int mid, int high) {
	
	const int n1 = mid - low + 1;
    const int n2 = high - mid;
	
	int left[n1];
    int right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];
	
	int i = 0, j = 0, k = low;
	
	while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
	
	while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int low, int high) {

	if (low < high) {
		
		int mid = (low + high) / 2;
		mergeSort(low, mid);
		mergeSort(mid + 1, high);
		
		merge(low, mid, high);
	}
}

int main(){
	
	cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
	
	mergeSort(0, n - 1);
	
	cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
	
	return 0;
}