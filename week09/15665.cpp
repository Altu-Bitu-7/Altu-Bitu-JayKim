#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
int m;


set <int> s;
vector <int> number;
int ssize=0;

//number의 각 요소가 사용되었는지 확인한다. 
//단, 여기서는 중복도 가능하게 하였으므로 체크할 요소는 없다. (??)

vector <int> is_used();
vector <int> perm;

void findAll(){
    
    if(perm.size()==m){
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i = 0; i < ssize; ++i) {
        
            perm.push_back(number[i]);  // 현재 숫자를 순열에 추가
            
            findAll();  // 재귀적으로 다음 숫자 선택
            
            perm.pop_back();  // 선택을 취소 (백트래킹)
        
    }
    
    
}

int main() {
    
    cin >> n >> m;
    
    for(int i=0 ; i<n ; i++){
        
        int k;
        cin >> k;
        s.insert(k);
        
    }
    
    //입력된수들을, 정렬된 상태로 중복없이 number에 넣음. 
    for(int x:s){
        number.push_back(x);
    }
    ssize=number.size();
    
    findAll();
    
    return 0;
}
