#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 시계방향 회전
void clockWise(vector<int>& m) {
    int temp = m[7];
    for (int i = 6; i >= 0; i--) {
        m[i + 1] = m[i];
    }
    m[0] = temp;
}

// 반시계방향 회전
void counterClockWise(vector<int>& m) {
    int temp = m[0];
    for (int i = 0; i < 7; i++) {
        m[i] = m[i + 1];
    }
    m[7] = temp;
}

// 회전 방향 결정
void spin(int direction, vector<int>& m) {
    if (direction == 1) {
        clockWise(m);
    } else if (direction == -1) {
        counterClockWise(m);
    }
}

int main() {
    int n;
    cin >> n;

    // 톱니바퀴 저장
    vector<vector<int>> matrix(n, vector<int>(8));

    // 톱니바퀴 값 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> matrix[i][j];
        }
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int numberWheel, direction;
        cin >> numberWheel >> direction;

        // 톱니바퀴 번호를 0부터 시작하도록 조정(0부터 n-1번 톱니바퀴. )
        numberWheel -= 1;

        // 각 톱니바퀴의 회전 방향을 저장하는 벡터, 그냥 n개 다 넣는다. 
        map <int, int> rotateDirection;  
      // 0은 회전하지 않음, 1은 시계방향, -1은 반시계방향
        rotateDirection[numberWheel] = direction;

        // 왼쪽으로 이동하며 맞물린 톱니바퀴 체크
        for (int checkWheel = numberWheel; checkWheel > 0; checkWheel--) {
            if (matrix[checkWheel][6] != matrix[checkWheel - 1][2]) { 
              //n극과 s극이 만났을 때는 돈다. 
                rotateDirection[checkWheel - 1] = rotateDirection[checkWheel] *(-1); 
            } else {
                break;  // 한번이라도 맞물리지 않으면 종료. 
            }
        }

        // 오른쪽으로 이동하며 맞물린 톱니바퀴 체크
        for (int checkWheel = numberWheel; checkWheel < n - 1; checkWheel++) {
            if (matrix[checkWheel][2] != matrix[checkWheel + 1][6]) {  // 톱니바퀴가 맞물린 경우
                rotateDirection[checkWheel + 1] = (-1)*rotateDirection[checkWheel];  // 반대 방향으로 회전
            } else {
                break;
            }
        }

        // 모든 톱니바퀴 회전 적용, 한번에. 
        for (int j = 0; j < n; j++) {
            if (rotateDirection[j] != 0) {  // 회전해야 하는 경우만 연산한다. 
                spin(rotateDirection[j], matrix[j]);
            }
        }
    }

    // 결과: 첫 번째 칸이 1인 톱니바퀴 개수 세기
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 1) {
            count++;
        }
    }

    cout << count;

    return 0;
}
