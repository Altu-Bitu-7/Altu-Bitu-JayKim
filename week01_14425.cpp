#include <iostream>
#include <set>

//vector 쓰니까 시간초과됨.....
//하긴 너무 쉽지
// vector를 이용하면 원소를 탐색하면 시간 복잡도가 O(n) (시간 초과)
// set은 이진트리 구조를 사용하므로 원소 탐색의 시간 복잡도가 O(log2n)! 
// set는 넣을 때 부터 정렬된 상태 / 고유한 원소를 유지한다. 
// set::find 함수를 사용한다. (key 값이 존재하면 해당 문자열을 뱉고, 존재하지 않으면 set::end 반환)

using namespace std;



int main() {

    int N;
    int M;
    int count =0;
  
    cin >> N >> M;
  
    set <string> input;

    for(int i=0 ; i<N ; i++){
      string str;
      cin >> str;
      input.insert(str);
    }

    for(int i=0 ; i<M ; i++){
      string str;
      cin >> str;

      if (input.find(str) != input.end()) { 
        //find함수란?
        //input이라는 set에서 str라는 문자열을 검색한다. 
        // 만약 str이 input에 존재한다면, 해당 iterator을 반환하고, 존재하지 않으면 end() 반복자를 반환한다. 
        // 따라서, 만약 input에 str이 존재하면 find함수는 해당 iterator를 반환하며 end()반복자를 반환하지 않으므로 count++.
          count++;
        }
      }
      
    

    cout << count;
  
    
    return 0;
}
