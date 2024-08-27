#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
  string a;
  string b;
  stack<int> aa;
  stack<int> bb;
  stack<int> sumit;

  cin >> a >> b;
  //더할 수 있게, 각자 숫자로 스택에 입력.
  for (char i : a) {
    int j = i - '0';
    aa.push(j);
  }
  for (char i : b) {
    int j = i - '0';
    bb.push(j);
  }

  int m = aa.size();
  int n = bb.size();

  if(n>m){
    aa.swap(bb);
  }
  m=aa.size();
  n=bb.size();
    //이제 aa는 bb보다 무조건 크거나 같다 
    //둘이 겹치는 만큼만 더한다.
    int p = 0;

    for (int i = 0; i < m; i++) {
      if(bb.empty()){
        bb.push(0);
      }
      int s = p + aa.top() + bb.top();

      if (s >= 10) {
        p = 1;
        sumit.push(s - 10);
      } else {
        p = 0;
        sumit.push(s);
      }
      aa.pop();
      bb.pop();

    }

    if(p==1){
      sumit.push(1);
    }


  while (!sumit.empty()) {
    cout << sumit.top();
    sumit.pop();
  }

  return 0;
}
