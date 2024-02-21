#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int grid[100][100];
bool visited[100][100] = {false, };
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
            int n_x = x + dx[i];
            int n_y = y + dy[i];

            if (can_go(n_x, n_y)) {
                visited[n_x][n_y] = true;
                q.push({n_x, n_y});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    visited[0][0] = true;
    q.push({0, 0});
    BFS();

    if (visited[n - 1][m - 1]) {
        cout << 1;
    }
    else {
        cout << 0;
    }
}