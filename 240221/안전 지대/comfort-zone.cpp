#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
int grid[50][50];
bool visited[50][50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool is_range(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int ans_k = 0;
int ans_cnt = 0;

void DFS(int x, int y, int k) {
    for (int i = 0; i < 4; i++) {
        int n_x = x + dx[i];
        int n_y = y + dy[i];

        if (is_range(n_x, n_y) && !visited[n_x][n_y] && grid[n_x][n_y] > k) {
            visited[n_x][n_y] = true;
            DFS(n_x, n_y, k);
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

    int max_value = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            max_value = max(max_value, grid[i][j]);
        }
    }

    for (int k = 1; k < max_value; k++) {
        int cnt_domain = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] > k) {
                    cnt_domain++;
                    visited[i][j] = true;
                    DFS(i, j, k);
                }
            }
        }

        if (cnt_domain > ans_cnt) {
            ans_cnt = cnt_domain;
            ans_k = k;
        }
    }

    cout << ans_k << ' ' << ans_cnt;
}