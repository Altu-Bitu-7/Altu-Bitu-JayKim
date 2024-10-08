#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;  
vector<int> network[MAX + 1];  
bool visited[MAX + 1];  
int infected_count = 0;  

// DFS 함수
void dfs(int node) {
    visited[node] = true;  // 현재 노드를 방문 처리
    for (int i = 0; i < network[node].size(); i++) {
        int next = network[node][i];
        if (!visited[next]) {
            infected_count++; 
            dfs(next);  
        }
    }
}

int main() {
    int num_computers, num_pairs;
    cin >> num_computers >> num_pairs;

    for (int i = 0; i < num_pairs; i++) {
        int u, v;
        cin >> u >> v;
        network[u].push_back(v);  // u와 v는 서로 연결됨
        network[v].push_back(u);  // 양방향 연결
    }

    dfs(1);


    cout << infected_count << endl;

    return 0;
}
