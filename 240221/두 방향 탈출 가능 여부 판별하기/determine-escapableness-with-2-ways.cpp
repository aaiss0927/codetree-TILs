#include <iostream>
using namespace std;

int n, m;
int is_snake[100][100] = {0, };
bool visited[100][100] = {false, };
int dx[2] = {1, 0};
int dy[2] = {0, 1};

bool is_range(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

bool can_go(int x, int y) {
    if (!is_range(x, y)) {
        return false;
    }

    if (visited[x][y]) {
        return false;
    }

    if (is_snake[x][y] == 0) {
        return false;
    }

    return true;
}

void DFS(int x, int y) {
    for (int i = 0; i < 2; i++) {
        int n_x = x + dx[i];
        int n_y = y + dy[i];

        if (can_go(n_x, n_y)) {
            visited[n_x][n_y] = 1;
            DFS(n_x, n_y);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> is_snake[i][j];
        }
    }

    visited[0][0] = true;
    DFS(0, 0);

    if (visited[n - 1][m - 1]) {
        cout << 1;
    }
    else {
        cout << 0;
    }
}