#include <iostream>
#include <queue>

using namespace std;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    priority_queue <int> present;
    cin >> n;

    for (int i=0 ; i<n ; i++){
        
        int m;
        cin >> m;

        if(m!=0){
            while(m--){
                int k;
                cin >>k;
                present.push(k);
            }
        }

        else{

            if(present.empty() ){
                cout << "-1" << "\n" ;
            }
            else{
                cout << present.top() << "\n";
                present.pop();
            }
        }
    }

    
    return 0;
}
