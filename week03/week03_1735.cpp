#include <iostream>
#include <stack>
using namespace std;


int gcd(int a, int b) {
  
  while (b != 0) {
      int temp = a % b;
      a = b;
      b = temp;
  }
  return a;
}

int lcm(int a, int b) {
  return (a * b) / gcd(a, b);
}

int main() { 

  int a,b;
  int m,n;

  cin >> a >> b;
  cin >> m >> n;

  int mo = lcm(b,n);
  int ja = (mo/b)*a+(mo/n)*m;
  int temp=gcd(mo, ja);

  if (temp!=1){
    mo=mo/temp;
    ja=ja/temp;
  }
  
  cout << ja <<" " << mo;
  
  return 0;
}
