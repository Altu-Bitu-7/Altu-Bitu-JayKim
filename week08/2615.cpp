#include <iostream>
#include <vector>
using namespace std;

int board[19][19];

vector<int> dx[] = {{0, 0}, {-1, 1}, {-1, 1}, {1, -1}};
vector<int> dy[] = {{-1, 1}, {0, 0}, {1, -1}, {1, -1}};

int countStones(int x, int y, int dir1, int dir2, int cnt) {
    if (cnt > 5) return 999; 

    int nx = x + dx[dir1][dir2];
    int ny = y + dy[dir1][dir2];
    if (nx < 0 || ny < 0 || nx >= 19 || ny >= 19) return cnt; // 범위 체크!

    // 같은 돌이 있으면 탐색을 계속한다. 
    if (board[nx][ny] == board[x][y]) 
        cnt = countStones(nx, ny, dir1, dir2, cnt + 1);

    return cnt;
}

int explore(int x, int y) {
    int result = 0;

    for (int i = 0; i < 4; i++) {
        int stones = 1; // 시작점 포함, 최소 1개

        for (int j = 0; j < 2; j++) {
            int nx = x + dx[i][j];
            int ny = y + dy[i][j];
            if (nx < 0 || ny < 0 || nx >= 19 || ny >= 19) continue;

            if (board[x][y] == board[nx][ny]) 
                stones += countStones(nx, ny, i, j, 1);
        }

        if (stones == 5) {
            result = board[x][y];
            break;
        }
    }
    return result;
}

int main() {
  cin.tie(0); 
  cout.tie(0); 
  ios::sync_with_stdio(false);

    int winner = 0, winnerX = 99, winnerY = 99;

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (board[i][j] != 0) {
                int result = explore(i, j);

                // 승리 조건을 만족하는 경우
                if (result != 0) {
                    // 가장 왼쪽 위에 있는 돌을 찾아옴
                    if (j < winnerY) {
                        winner = result;
                        winnerX = i;
                        winnerY = j;
                    }
                }
            }
        }
    }


    if (winner) {
        cout << winner << "\n";
        cout << winnerX + 1 << " " << winnerY + 1;
    } else {
        cout << "0";
    }

    return 0;
}
