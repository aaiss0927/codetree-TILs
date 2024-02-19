#include <iostream>
#include <algorithm>
using namespace std;

int n;
int grid[4][4];
pair<int, int> grid_dir[4][4];
pair<int, int> dir[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} }; 

bool is_range(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

bool exit_condition(int x, int y) {
    for (int i = 1; i < n; i++) {
        int nx = x + grid_dir[x][y].first * i;
        int ny = y + grid_dir[x][y].second * i;

        if (is_range(nx, ny) && grid[nx][ny] > grid[x][y]) {
            return false;
        }
    }

    return true;
}

int ans = 0;
int cnt = 0;

void process(int x, int y) {
    if (exit_condition(x, y)) {
        ans = max(cnt, ans);
        return;
    }

    for (int i = 1; i < n; i++) {
        int nx = x + grid_dir[x][y].first * i;
        int ny = y + grid_dir[x][y].second * i;

        if (is_range(nx, ny) && grid[nx][ny] > grid[x][y]) {
            cnt++;
            process(nx, ny);
            cnt--;
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
            int dir_num; cin >> dir_num; dir_num--;
            grid_dir[i][j] = dir[dir_num];
        }
    }

    int r, c; cin >> r >> c; r--; c--;

    process(r, c);

    cout << ans;
}