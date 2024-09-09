#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int ans=0;
    cin >> n;

    for (int i=0 ; i<n ; i++){
        string str;
        int m;
        cin >> str;

        if(str=="empty"){
            ans=0;
        }
        else if(str=="all"){
            ans=(1<<21)-1;
        }
        else{
            cin >> m;

            if(str=="add"){
                ans=ans|(1<<m);
            }
            else if(str=="remove"){
                ans=ans&~(1<<m);
            }
            else if(str=="toggle"){
                ans=ans^(1<<m);
            }
            else if(str=="check"){
                cout << ((ans&(1<<m))!=0) << "\n"; 
                //ans를 m번째 비트가 1인 숫자와 &연산을 하여, 만약 ans의 m번째 비트가 1이 아니라면 0이나오게 된다. 
            }
        }
    }
    return 0;
}