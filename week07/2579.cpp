#include <iostream>
#include <vector>

using namespace std;

int maxi(vector <int> st){
  
  int n=st.size();
  if(n==0) return 0;
  if(n==1) return st[0];
  if(n==2) return st[0]+st[1];

  //dp[i]는 i번째 계단까지의, 최대 점수.
  //피보나치 느낌으로 

  vector <int> dp(n);

  dp[0] = st[0];
  dp[1] = st[0] +st[1];
  dp[2] =max(st[0]+st[2], st[1]+st[2]); //0,1 1,2 중에서 최대치를 구한다. 

  for(int i=3; i<n ; i++){
    dp[i] = max(dp[i-2]+st[i], dp[i-3]+st[i-1]+st[i]);
    //당장의 상태에서, 가장 큰 상태를 고른다!
  }

  
  return dp[n-1];
}


int main() {

  int n;
  cin >> n;
  vector<int> stairs(n);

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    stairs.push_back(k);
  }

  cout << maxi(stairs);

  return 0;
}
