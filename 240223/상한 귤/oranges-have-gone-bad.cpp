#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// 0 - 아무것도 없음 / 1 - 귤 / 2 - 초기 상한 귤

int n, k;
int grid[100][100];
bool visited[100][100] = {false, };
int step[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<pair<int, int>> wasted;

bool in_range(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

bool can_go(int x, int y) {
    return (in_range(x, y) && !visited[x][y] && (grid[x][y] != 0));
}

queue<pair<int, int>> q;

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
                step[nx][ny] = min(step[nx][ny], step[x][y] + 1);
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 2) {
                wasted.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            step[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                step[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < wasted.size(); i++) {
        visited[wasted[i].first][wasted[i].second] = true;
        step[wasted[i].first][wasted[i].second] = 0;
        q.push({wasted[i].first, wasted[i].second});
    }

    BFS();

    // grid[i][j] == 2 -> step[i][j] = 0
    // grid[i][j] == 0 -> step[i][j] = -1
    // grid[i][j] == 1 && step[i][j] = -> step[i][j] = 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && step[i][j] == INT_MAX) {
                step[i][j] = -2;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << step[i][j] << ' ';
        }
        cout << '\n';
    }
}