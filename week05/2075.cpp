#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    
    priority_queue<int, vector<int>, greater<int>> pq; // 오름차순으로 넣어주는 힙 생성

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k;
            cin >> k;

            // 우선 pq에 n개만큼 넣기
            if (pq.size() < n) {
                pq.push(k);
            }
           
            else if (k > pq.top()) {
                pq.pop(); // pq의 top에는 현재까지의 최솟값이 들어있다. 따라서 이런 식으로 갱신을 해주다 보면, 마지막엔 제일 위에 5번째로 큰 값 즉, n*n-5번째로 작은 값이 남게 된다.!)
                pq.push(k);
            }
        }
    }

    cout << pq.top() << "\n";

    return 0;
}
