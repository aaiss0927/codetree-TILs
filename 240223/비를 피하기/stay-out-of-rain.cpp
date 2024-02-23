#include <iostream>
#include <queue>
using namespace std;
// 0 - 이동 가능 / 1 - 벽 / 2 - 사람 / 3 - 비 피할 수 있는 공간
// 1 제외 모두 이동 가능

int n, h, m;
int grid[100][100];
bool visited[100][100] = {false, };
int step[100][100] = {0, };
int answer[100][100] = {0, };
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void setup() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
            step[i][j] = 0;
        }
    }
}

bool in_range(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

bool can_go(int x, int y) {
    return (in_range(x, y) && !visited[x][y] && (grid[x][y] != 1));
}

queue<pair<int, int>> q;

int min_elapsed;

void BFS() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (can_go(nx, ny)) {
                visited[nx][ny] = true;
                step[nx][ny] = step[x][y] + 1;
                q.push({nx, ny});

                if (grid[nx][ny] == 3) {
                    min_elapsed = step[nx][ny];
                    q = queue<pair<int, int>>();
                    return;
                }
            }
        }
    }
}

int main() {
    cin >> n >> h >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                min_elapsed = -1;
                setup();
                visited[i][j] = true;
                q.push({i, j});
                BFS();

                answer[i][j] = min_elapsed;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
}