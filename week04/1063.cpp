#include <iostream>
#include <vector>

using namespace std;

void inst(const string& str, int& g, int& s){

        if (str == "R") {
            g += 1;  
        }
        else if (str == "L") {
            g -= 1;  
        }
        else if (str == "B") {
            s -= 1;  
        }
        else if (str == "T") {
            s += 1;  
        }
        else if (str == "RT") {
            g += 1; 
            s += 1;
        }
        else if (str == "LT") {
            g -= 1; 
            s += 1;
        }
        else if (str == "RB") {
            g += 1;
            s -= 1;
        }
        else if (str == "LB") {
            g -= 1;
            s -= 1;
        }
    
}

void move(string king, string rock, vector <string> where){
    int sz= where.size();

    int kg= king[0] - 'A' +1;
    int ks= king[1] - '0';

    int rg= rock[0] - 'A' +1;
    int rs = rock[1] - '0';

    for (int i = 0; i < sz; i++) {        
        int prev_kg = kg;
        int prev_ks = ks;

        // 왕의 위치 이동
        inst(where[i], kg, ks);    

        if(kg>8 || kg<1 || ks>8 || ks<1){
            kg=prev_kg;
            ks=prev_ks;
            continue;
        }
        // 왕의 새 위치가 바위와 같은 경우 바위도 이동
        if (kg == rg && ks == rs) {
            int prev_rg = rg;
            int prev_rs = rs;

            inst(where[i], rg, rs);

            // 바위가 범위를 벗어나면 왕의 이동을 취소
            if (rg < 1 || rg > 8 || rs < 1 || rs > 8) {
                kg = prev_kg;
                ks = prev_ks;
                rg = prev_rg;
                rs = prev_rs;
            }
        }
    }

    // 최종 위치 출력
    cout << static_cast<char>(kg + 'A' - 1) << ks << '\n';
    cout << static_cast<char>(rg + 'A' - 1) << rs << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string king;
    string rock;
    int n;

    cin >> king >> rock >> n;

    vector <string> where(n);

    for (int i=0 ; i<n ; i++){
        string w;
        cin >> w;
        where[i]=w;
    }

    move(king, rock, where);

    return 0;
}