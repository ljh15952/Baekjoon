#include <iostream>
#include <algorithm>

using namespace std;

long long int arr[100001];

int main(){
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	
	sort(arr,arr+n);
	
	long long int max = 1;
	long long int cnt = 1;
	long long int ans = arr[0];
	
	for(int i = 1; i < n; ++i){
		if(arr[i]==arr[i-1])
			cnt++;
		else
			cnt=1;
		
		if(max<cnt){
			max=cnt;
			ans=arr[i];
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}