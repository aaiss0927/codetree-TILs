#include <iostream>
#include <algorithm>
using namespace std;

int n;
int grid[100][100];
bool visited[100][100] = {false, };
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int cnt_cell;
int cnt_exp_block = 0;
int max_size_block = 1;

bool is_range(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

bool can_go(int x, int y, int n_x, int n_y) {
    if (!is_range(n_x, n_y)) {
        return false;
    }

    if (visited[n_x][n_y]) {
        return false;
    }

    if (grid[x][y] != grid[n_x][n_y]) {
        return false;
    }

    return true;
}

void DFS(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int n_x = x + dx[i];
        int n_y = y + dy[i];

        if (can_go(x, y, n_x, n_y)) {
            cnt_cell++;
            visited[n_x][n_y] = true;
            DFS(n_x, n_y);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                cnt_cell = 1;
                visited[i][j] = true;
                DFS(i, j);

                max_size_block = max(max_size_block, cnt_cell);

                if (cnt_cell >= 4) {
                    cnt_exp_block++;
                }
            }
        }
    }

    cout << cnt_exp_block << ' ' << max_size_block;
}