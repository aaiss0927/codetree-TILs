#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int n, k;
int grid[100][100];
bool visited[100][100] = {false, };
vector<pair<int, int>> start_pnts;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

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

    if (grid[x][y] == 1) {
        return false;
    }

    return true;
}

queue<pair<int, int>> q;
int visited_cell = 0;

void BFS() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int n_x = x + dx[i];
            int n_y = y + dy[i];

            if(can_go(n_x, n_y)) {
                visited_cell++;
                visited[n_x][n_y] = true;
                q.push({n_x, n_y});
            }
        }
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int r, c; cin >> r >> c; r--; c--;
        start_pnts.push_back({r, c});
    }

    for (int i = 0; i < start_pnts.size(); i++) {
        if (!visited[start_pnts[i].first][start_pnts[i].second]) {
            visited_cell++;
            visited[start_pnts[i].first][start_pnts[i].second] = true;
            q.push({start_pnts[i].first, start_pnts[i].second});
            BFS();
        }
    }

    cout << visited_cell;
}