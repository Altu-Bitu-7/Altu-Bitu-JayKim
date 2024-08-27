#include <iostream>
#include <queue>

using namespace std;


int main(){
  int n;
  int k;
  cin >> n >> k;
  
  queue<int> table;
  
  
  for (int i=1; i<=n ; i++){
    table.push(i);
  }
  cout << "<";
  while(!table.empty()){
    for (int i=1; i<k ; i++){
      table.push(table.front());
      table.pop();
    }  
    cout << table.front();
    table.pop();
    
    if (!table.empty())
      cout << ", ";
  }
    cout << ">";
  return 0;
}