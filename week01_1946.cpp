#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  
  while(T--){
    //여기서부터 하나의 테스트 케이스. 
    int N;
    cin >> N;
    vector <pair<int, int>> rank(N);
    
    for(int i=0; i<N ; i++){
      int paper;
      int talk;

      cin >> paper >> talk;
      rank[i].first=paper;
      rank[i].second=talk;
      
    }
    
    sort(rank.begin(), rank.end());
    
    int counter = 1; // 서류 1등은 선발. 
    int min = rank[0].second; // 서류 1등의 면접 점수를 첫번째 min으로 넣는다. 

    // 서류 심사 순위에 따라 map을 순회
    for(int i=1; i<N ; i++){
      if(rank[i].second < min){
        counter++;
        min=rank[i].second;
      }
    }
    cout << counter << "\n";
    
  }
  return 0;
}
