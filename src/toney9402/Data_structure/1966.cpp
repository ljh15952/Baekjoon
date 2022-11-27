#include <iostream>

using naemspace std;

int main(){
  
  cout << "프린터 큐" << endl;
  
  return 0;
}

/*
Queue의 가장 앞에 있는 문서의 중요도를 확인한다.
나머지 문서들 중 현재 문서 보다 중요도 가 높은 문서가 하나라도 있다면, 이 문서를 인쇄하지 않고
Queue의 가장 뒤에 재배치 한다. 그렇지 않으면 바로 인쇄를 한다.

*/
