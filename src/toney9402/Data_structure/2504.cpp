#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	
	string str;
	cin >> str;
    
	stack<char> s;
    int ans = 0;
	int tmp = 1;
    
    for(int i = 0; i < str.length(); i++){
		char it = str[i];
        if(it == '('){
			tmp *= 2;
			s.push('(');
		}else if(it == '['){
			tmp *= 3;
			s.push('[');
		}else if(it == ')'){
			if(s.empty() || s.top() != '('){
				ans = 0;
				break;
			}
			if(str[i-1] == '('){
				ans += tmp;
				tmp /= 2;
				s.pop();
			}else{
				tmp /= 2;
				s.pop();
			}
		}else if(it == ']'){
			if(s.empty() || s.top() != '[') {
                ans = 0;
                break;
            }if(str[i-1] == '[') {
                ans += tmp;
                tmp /= 3;
                s.pop();
            }else {
                tmp /= 3;
                s.pop();
            }
		}
    }
	
	if(!s.empty())
		ans = 0;
 
    cout << ans << "\n";
	

        
    return 0;
}

/*


*/