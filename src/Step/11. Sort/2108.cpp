#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	
	int n;
	
	cin >> n;
	
	vector<int> arr;
	
	for(int i = 0; i < n; i++){
		int num;
		scanf("%d",&num);
		
		arr.push_back(num);
	}
	
	//0. 정렬
	sort(arr.begin(),arr.end());

	//1. 산술 평균
	int sum = 0;
	double size = arr.size();
	for(int i : arr){
		sum += i;
	}
	int avg = round(sum / size);
	if(avg == 0){
		cout << "0" << endl;
	}else{
		cout << avg << endl;
	}
	
	//2. 중앙값
	cout << arr[size / 2] << endl;
	
	//3. 최빈값
	if(n > 1){
		int arr2[8001] = {0,};
		for(int i : arr){
			arr2[4000 + i]++;
		}

		int max = arr[0];
		vector<int> maxArr;
		for(int i = 0; i < 8001; i++){
			if(max < arr2[i]){
				max = arr2[i];
			}
		}
		
		for(int i = 0; i < 8001; i++){
			if(max == arr2[i]){
				maxArr.push_back(i-4000);
			}
		}

		sort(maxArr.begin(),maxArr.end());
		
		if(maxArr.size() > 1){
			cout << maxArr[1] << endl;
		}else{
			cout << maxArr[0] << endl;
		}
		
	}else{
		cout << arr[0] << endl;
	}
	
	
	//4. 범위
	cout << arr.back() - arr.front() << endl;
	
	return 0;
}