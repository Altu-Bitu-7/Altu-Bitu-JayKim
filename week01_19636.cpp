#include <iostream>
#include <cmath>

using namespace std;

int main() {

  int W0; // 다이어트 전 체중
  int I0; // 다이어트 전 일일 에너지 섭취량 (==일일 기초 대사량)
  int T; // 기초 대사량 변화 역치.
  
  int D; // 데시의 다이어트 기간
  int I; // 다이어트 기간 일일 에너지 섭취량(+)
  int A; // 다이어트 기간 일일 활동 대사량(-)

  
  //체중은 change=I-(M+A)만큼 더해진다.
  // if change 절대값 > T 이면 , I0가 (int)(change/2)만큼 더해짐. 대신 이건 체중변화 이후에 연산됨. 
  // 나머지는 ...나중에...

  cin >> W0 >> I0 >> T;
  cin >> D >> I >> A;
  
  //일일 기초 대사량이 변화하지 않을 때
  int M=I0; // 다이어트 전 일일 기초 대사량
  int W=W0; // 데시의 다이어트 이후 체중
  int change; // 데시의 일일 체중 변화량
  
  
  change=I-(M+A);
  W+=(change*D);

  if(W<=0){
    cout << "Danger Diet" << "\n";
  }
  else{
    cout << W << " "<< M << "\n";
  }
  
  //일일 기초 대사량이 변화할 때
  
  int CI=I0; // 데시의 다이어트 이후 일일 기초 대사량 (바뀌었을 때 기준)
  W=W0;
  change=0;
  string yoyo;
  
  for(int i = 0 ; i<D ; i++){
    change=I-(CI+A);
    W+=change;
    
    if (abs(change) > T) {
        CI+=float(change)/2.0;
      
    }

  }

  if(W<=0 || CI<=0){
    cout <<"Danger Diet" << "\n";
  }
  else{
    if((I0-CI)>0) yoyo="YOYO";
    else yoyo="NO";  
    cout << W << " "<< CI << " " << yoyo;
  }
  
  return 0;
}
