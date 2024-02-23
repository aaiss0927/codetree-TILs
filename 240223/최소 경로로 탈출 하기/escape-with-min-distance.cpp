#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int grid[100][100];
bool visited[100][100] = {false, };
int step[100][100] = {0, };
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<pair<int, int>> q;

bool is_range(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool can_go(int x, int y) {
    if (!is_range(x, y)) {
        return false;
    }

    if (visited[x][y]) {
        return false;
    }

    if (grid[x][y] == 0) {
        return false;
    }

    return true;
}

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
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    visited[0][0] = true;
    step[0][0] = 0;
    q.push({0, 0});
    BFS();

    if (step[n - 1][m - 1] == 0) {
        cout << -1;
        return 0;
    }

    cout << step[n - 1][m - 1];
}