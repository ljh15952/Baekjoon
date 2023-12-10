#include <iostream>
#include <algorithm>

using namespace std;

int arr[8] = {24,75,92,83,61,48,97,50};

struct MinMax {
    int minVal;
    int maxVal;
};

MinMax findMinMax(int low, int high){
	
	MinMax result, left, right;
	
	if(low == high){
		result.minVal = arr[low];
        result.maxVal = arr[low];
        return result;
	}
	
	int mid = (low + high) / 2;
    left = findMinMax(low, mid);
    right = findMinMax(mid + 1, high);
	
	result.minVal = min(left.minVal, right.minVal);
    result.maxVal = max(left.maxVal, right.maxVal);
	
	return result;
}

int main(){
	
	MinMax result = findMinMax(0, 8-1);
	
	cout << "Minimum value: " << result.minVal << endl;
    cout << "Maximum value: " << result.maxVal << endl;
	
	return 0;
}