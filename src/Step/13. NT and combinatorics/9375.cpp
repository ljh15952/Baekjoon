#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
	
	int t;
	
	cin >> t;
	
	/* 
	공식 
	headgear 2
	eyewear 1
	-> (2+1) * (1+1) - 1(둘 다 안 입은 경우) = 5
	
	*/
	
	int n;
	string name, tag;
	for(int i = 0; i < t; ++i){
		
		map<string,int> m;
		cin >> n;
		
		while(n--){
			cin >> name >> tag;
			if(m.find(tag) == m.end()){
				m.insert({tag,1});
			}else{
				m[tag]++;
			}
		}
		
		int ans = 1;
		
		for(auto i : m){
			ans *= (i.second+1);
		}
		ans -= 1;
		cout << ans << '\n';
	}
	
	return 0;
}