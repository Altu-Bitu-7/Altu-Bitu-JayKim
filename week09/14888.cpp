#include <iostream>
#include <vector>

using namespace std;
int n;
vector <int> numb(n);
vector <int> oper(4);
vector <int> is_used(4,0); //각 연산자가 사용되었는지 확인한다. 
//oper의 각 요소와 같아지면, 그때 사용을 멈춘다. 

vector <int> cal;

int small=1000000001;
int big=-1000000001;

void calculate(){
    
    int temp=numb[0];
    
    for(int i=1 ; i<n ; i++){
        
        
        switch (cal[i-1])
        {
            
            case 0: 
                temp+=numb[i];
                break;
            case 1: 
                temp-=numb[i];
                break;
            case 2: 
                temp*=numb[i];
                break;
            case 3: 
                temp/=numb[i];
                break;
            
        }
    
    }
    
    if(small>temp) small=temp;
    if(big<temp) big=temp;
    
}

void findAll(){
    
    
    if(cal.size()==n-1){
        calculate();
        return;
    }
    
    //백트래킹 사용하서, 그냥 다 곱해보자! 
    for (int i = 0; i < 4; ++i) {
        if (is_used[i] < oper[i]) {  // 아직 사용할 수 있는 연산자라면
            cal.push_back(i);  // 현재 숫자를 순열에 추가
            is_used[i] +=1 ;  // 숫자를 사용 처리
            findAll();  // 재귀적으로 다음 숫자 선택
            
            cal.pop_back();  // 선택을 취소 (백트래킹)
            is_used[i] -=1;  // 사용된 표시를 해제
        }
    }
    
}
int main() {
    
    cin >> n;
    numb.resize(n);
    //입력받는 부분
    for(int i=0 ; i< n ; i++){
        int k;
        cin >> k;
        numb[i]=k;
    }
    
    for(int i=0 ; i<4 ; i++){
        int p;
        cin >> p;
        oper[i]=p;
    }
    
    findAll();
    
    cout << big << '\n';
    cout << small;
    
    
    return 0;
}
