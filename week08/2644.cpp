#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, a, b, m;
vector<int> graph[101];  
int visited[101];        // 방문 여부 체크용 배열
int dist[101];           // 촌수 기록용 배열

int bfs(int start, int target) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    dist[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : graph[current]) {
            if (!visited[next]) {
                visited[next] = 1;
                dist[next] = dist[current] + 1;
                q.push(next);

                // 목표 노드에 도달하면 촌수를 반환
                if (next == target) {
                    return dist[next];
                }
            }
        }
    }

    return -1;  
}

int main() {
    // 입력 받기
    cin >> n;      
    cin >> a >> b;   
    cin >> m;      

    // 부모 자식 관계 입력 받기
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);  // 부모-자식 관계
        graph[y].push_back(x); 
    }


    int result = bfs(a, b);

    cout << result << endl;

    return 0;
}
