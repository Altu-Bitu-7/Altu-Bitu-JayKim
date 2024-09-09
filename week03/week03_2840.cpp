#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main() { 

  int n, k;
  
  cin >> n >> k;

  vector <char> wheel(n,'?');
  set<char> used_letters;
  
  int pointer=0;
  string str="yes";
  
  for (int i=0 ; i<k ; i++){
    int s;
    char lucky;
    cin >> s >> lucky;

    //pointer는 항상 n보다 작다. 
    
    pointer = (pointer + s) % n;

    if(wheel[pointer]!=lucky && wheel [pointer]!='?'){ //비지 않은 곳에 새로운 문자가 있다. 
      str="no";
      break;
    }
    else if(wheel[pointer]=='?' && used_letters.count(lucky) > 0){
      str="no";
      break;
    }
    else{
      wheel[pointer] = lucky; // 바퀴에 알파벳 설정
      used_letters.insert(lucky); // 사용된 알파벳 등록
    }
    
    
  }

  if (str == "yes") {
    // 최종 화살표 위치부터 시계방향으로 출력
    for (int i = 0; i < n; i++) {
        cout << wheel[(pointer - i + n) % n];
    }
  } else {
    cout << "!";
  }
  
  
  

  
  return 0;
}
