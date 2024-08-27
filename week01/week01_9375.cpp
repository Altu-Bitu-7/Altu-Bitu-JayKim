#include <iostream>
#include <map> 
#include <vector>

using namespace std;

int main() {
  int N;
  
  cin >> N;
  for (int i =0; i<N ; i++){
    int M;
    
    cin >> M;
    map <string , int > clothes;
    
    for (int j=0; j<M; j++){
      string name;
      string kind;


      cin >> name >> kind;
      
      if (clothes.find(kind) != clothes.end()) {
        clothes[kind]+=1;
      }
      else{
        clothes[kind]= 1;
      }
    }
      int counter=1;
      
      for (auto iter = clothes.begin(); iter != clothes.end(); iter++) {
        //auto: iter의 타입을 자동적으로 알려줌.
        // iter: clothes의 value를 처음부터 끝까지 순회하는 반복자. 
        counter *= (iter->second + 1);
        //iter->second+1 : second는 여기서 value임. 
        // counter에 second+1의 값을 곱하여 갱신한다. 

        //이게 가능한 이유? 
        // iter는 clothes의 모든 value값에 1을 더한다 (입지 않은 경우를 더하는것. 투명 옷이라 하자. )
        // 이 투명 옷이 있다면, 입지 않은 상태까지 쉽게 곱할 수 있다. 
    }
      counter--; // 모두 투명 옷만 입었을 때. 
      // 출력
   



    cout << counter << '\n';
  }

  
  return 0;
}
