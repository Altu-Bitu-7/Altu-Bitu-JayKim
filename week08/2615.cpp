#include <iostream>
using namespace std;

int board[19][19];
int dx[] = {0, 1, 1, -1}; 
int dy[] = {1, 0, 1, 1};

// 정확히 5개의 바둑알이 연속되는지 확인하는 함수
bool isValid(int x, int y, int dir) {
    int color = board[x][y];
    int count = 1;

    // 한 방향으로 4개의 돌을 더 체크
    for (int i = 1; i < 5; i++) {
        int nx = x + dx[dir] * i;
        int ny = y + dy[dir] * i;

        if (nx < 0 || ny < 0 || nx >= 19 || ny >= 19 || board[nx][ny] != color)
            return false; // 범위를 벗어나거나 다른 색상이면 실패
    }
    int prev_x = x - dx[dir];
    int prev_y = y - dy[dir];
    int next_x = x + dx[dir] * 5;
    int next_y = y + dy[dir] * 5;

    if ((prev_x >= 0 && prev_y >= 0 && prev_x < 19 && prev_y < 19 && board[prev_x][prev_y] == color) ||
        (next_x >= 0 && next_y >= 0 && next_x < 19 && next_y < 19 && board[next_x][next_y] == color)) {
        return false;
    }

    return true;

int main() {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (board[i][j] != 0) { // 바둑알이 있는 곳에서 탐색 시작
                for (int dir = 0; dir < 4; dir++) {
                    if (isValid(i, j, dir)) {
                        cout << board[i][j] << "\n";
                        cout << i + 1 << " " << j + 1 << "\n"; 
                        return 0;
                    }
                }
            }
        }
    }

    // 승부가 나지 않았을 경우
    cout << "0\n";
    return 0;
}
