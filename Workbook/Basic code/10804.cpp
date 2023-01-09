#include <bits/stdc++.h>
using namespace std;




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int cards[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    
    int a, b;
    cin >> a >> b;
    int tmp[20];
    memcpy(&tmp,&cards, sizeof(cards));
    
    
    for(int j = a; j <= b; ++j){
        cards[a + j] = tmp[b - j];
    }
    
    // for(int i = 0; i < 10; ++i){
        
    // }
    
    for(int i = 0; i < 20; ++i){
        cout << cards[i] << ' ';
    }
    
    return 0;
}

// keep solving..
