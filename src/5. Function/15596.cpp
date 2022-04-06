#include <vector>

long long sum(std::vector<int> &a){
	long long num = 0;
	for(int i = 0; i < a.size(); i++){
		num += a[i];
	}
	return num;
}

