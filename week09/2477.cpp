#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector <int> dir(6);
    vector <int> len(6);

    vector <pair <int, int>> v(6);
    
    vector <int> is_used(5,0);

    for (int i=0; i<6 ; i++){
        int d;
        int l;
        
        cin >> d >> l;

        dir[i]=d;
        len[i]=l;

        v[i]=make_pair(d,l);
        
        //방향 나온 빈도 체크하기
        
        is_used[d]++;
        
    }
    
    int total=1;
    int minus=1;

    vector <int> two;
    
    for(int i=1; i<5 ; i++){
        //한번만 나온 방향의 경우, 즉 전체 사각형의 크기를 먼저 구한다
        if(is_used[i]==1){
            for (int j=0 ; j<6 ; j++){
                if(v[j].first==i){
                    total*=v[j].second;

                    if(j>=3) two.push_back(j-3);
                    else two.push_back (j+3);
                }
            }
        
        }
    }

    minus=len[two[0]]*len[two[1]];

    cout << (total-minus)*n;
    
        
    
    
    return 0;
}
