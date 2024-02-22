#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int grid[200][200];
int n_grid[200][200];
bool visited[200][200];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int last_size;
queue<pair<int, int>> q;
vector<pair<int, int>> glacier;

void setup() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }
}

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

    if (grid[x][y] == 1) {
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
                q.push({ n_x, n_y });
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 1) {
                glacier.push_back({ i, j });
            }
        }
    }

    int t = 0;

    while (!glacier.empty()) {
        t++;
        last_size = 0;
        setup();

        visited[0][0] = true;
        q.push({ 0, 0 });

        BFS();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                n_grid[i][j] = grid[i][j];
            }
        }

        for (auto it = glacier.begin(); it != glacier.end();) {
            bool flag_erase = false;

            for (int i = 0; i < 4; i++) {
                int n_i = it->first + dx[i];
                int n_j = it->second + dy[i];

                if (grid[n_i][n_j] == 0 && visited[n_i][n_j]) {
                    last_size++;
                    n_grid[it->first][it->second] = 0;
                    it = glacier.erase(it);
                    flag_erase = true;
                    break;
                }
            }

            if (!flag_erase) {
                it++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = n_grid[i][j];
            }
        }
    }

    cout << t << ' ' << last_size;
}