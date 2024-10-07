#include <iostream>
#include <vector>

using namespace std;

int maxi(vector <int> sy){
  
  int n=sy.size();
  if(n==0) return 0;

  //dp[i]는, sy[i]까지의 가장 긴 증가하는 부분 수열의 길이이다. 
  vector <int> dp(n,1);

  for(int i=1 ; i<n ; i++){
    for(int j=0 ; j<i ; j++){
      if(sy[i]>sy[j]){
        dp[i] = max(dp[i], dp[j]+1);
        //이유
        //현재 인덱스는 i이며, i 이전의 모든 수열의 구성을 돈다
        //이때 현재 sy[i]값보다 작은 sy[j]값을 발견하면, 
        //dp[i]에서, 현재 dp값과 dp[j]+1, 즉 당시 증가하는 수열에서 +1을 한 수 보다 큰 값을 고른다. 
        //큰 값으로 업데이트. 
      }
    }
  }

  int longest=0;
  //dp에서 제일 큰 값 고르기
  for(int i=0 ; i<n ; i++){
    longest=max(longest,dp[i]);
  }

  return longest;
}


int main() {

  int n;
  cin >> n;
  vector<int> sy(n);

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    sy[i]=k;
  }

  cout << maxi(sy);

  return 0;
}
