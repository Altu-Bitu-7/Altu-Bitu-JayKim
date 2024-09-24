#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> speed(n);  // long long 자료형 사용

    for (int i = 0; i < n; i++) {
        cin >> speed[i];
    }

    // 역순으로 내려가며 비교 시작
    long long curSpeed = speed[n - 1];

    for (int i = n - 2; i >= 0; i--) { 
      
        if (curSpeed < speed[i]) {
            curSpeed = speed[i];  // 속도가 더 크면 그대로 유지
        } else {
            // 최소한의 배수로 올림
            curSpeed = ((curSpeed + speed[i] - 1) / speed[i]) * speed[i];
        }
    }

    cout << curSpeed; 
    return 0;
}
