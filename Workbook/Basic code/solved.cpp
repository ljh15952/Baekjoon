// 파일은 만들지 않음

// 9달 전 코드 2020	412
#include <iostream>

using namespace std;

int main(){
	int n,t;
	
	cin >> n >> t;
	
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a < t)
			cout << a << " ";
	}
	
	return 0;
}

// 지금 푼 2020	0
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, X;
    cin >> N >> X;
    
    for(int i = 0; i < N; ++i){
        int a;
        cin >> a;
        if(a < X) cout << a << ' ';
    }
    
	return 0;
}
