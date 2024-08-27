#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int sumit(string s1){
  int sum=0;
  
  for (int i = 0 ; i < s1.size(); i++) {
    if (isdigit(s1[i])) { // char이 숫자인 경우에만 쓴다. 
      sum += s1[i] - '0'; // char을 int 값으로 바꾸는 방법. 아스키코드를 사용
      //(int)s1[i]로 하면 그냥 s1의 아스키코드값을 출력한다...
    }
  }
  return sum;
}


bool cmp(string s1, string s2){
  if (s1.size() != s2.size()) { // 길이 비교.
      return s1.size() < s2.size();
    }
  else if (sumit(s1) != sumit(s2)) { //숫자 합 비교
      return sumit(s1) < sumit(s2);
    }
  return s1 < s2; //이렇게 아무것도 안넣으면 그냥 사전순으로 해주나봄 
}

int main() {
    int N;
    cin >> N;

    vector<string> cereals; // 벡터 선언

    for (int i = 0; i < N; i++) {
        string cereal;
        cin >> cereal;
        cereals.push_back(cereal); // 입력 값을 벡터에 추가
    }

    sort(cereals.begin(), cereals.end(), cmp);
    //여기서 sort는?
    //cereals라는 벡터 (정리할 컨테이너의 이름)을, 처음부터 끝까지 cmp라는 사용자 지정 함수에 따라 정리한다. 
    // cmp가 없다면 그냥 오름차순으로 정리한다. 
    // cmp는 true false를 도출하게 조정
    // 뭐가 어쩌고저쩌고 많은데 그냥 cmp에 따라 조정하는 함수라고 생각하자.

    for (int i = 0; i < N; i++) {
      cout << cereals[i] << '\n';
    }
    

    return 0;
}
