#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main() {
    string str;
    
    while(true){
      getline(cin, str);
      
      // '.'만 입력되었을 경우 종료
      if (str == ".") {
          break;
      }
      
      queue<char> one;
      stack<char> check;
      string yn="yes";
      
      for (char a : str) { //모든 char을 line이라는 string 전체를 순회하며 one에 넣는다. 
          one.push(a);
      }

      while (true) {
        //one이라는 한 줄을 담은 큐가 비면, 멈춘다. 
        if (one.empty()){
          break;
        }
        
        //한 줄을 담은 큐 (one)에서, 제일 앞에 있는 문자열을 꺼내고 삭제한다. 
        char cp = one.front();
        one.pop();
 
        //체킹포인트
        if(cp=='(' || cp=='['){
          check.push(cp);
        }
        else if(cp==')'){
          if (check.empty() || check.top() != '(') {  // 스택이 비어 있는지 먼저 확인
            yn = "no";
            break;
          }
          check.pop();
        }
        else if(cp==']'){
          if (check.empty() || check.top() != '[') {  // 스택이 비어 있는지 먼저 확인
            yn = "no";
            break;
          }
          check.pop();
        }
      } //while true문 끝자락. 여기서 한 줄의 검사가 끝난다. 
      //만약 한 줄을 끝까지 돌았음에도 스택에 뭐가 남아있다면, yn=no로 설정한다. 끝까지 다 돌지 않았어도 ㄱㅊ. 그 경우에도 어차피 no임. 
      if (!check.empty()) {
          yn = "no";
      }
      
      cout << yn << "\n";
    
      
    } //모든 입력을 받고, 모두 끝남. 

    return 0;
}

    










  
    