#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n, k;
int r1, c1, r2, c2;
int grid[100][100];
int temp_grid[100][100];
bool visited[100][100];
int step[100][100];
vector<pair<int, int>> walls;
queue<pair<int, int>> q;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int ans = INT_MAX;

bool in_range(int x, int y) {
    return (x >= 0 && x < n&& y >= 0 && y < n);
}

bool can_go(int x, int y) {
    return (in_range(x, y) && temp_grid[x][y] == 0 && !visited[x][y]);
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
                q.push({ nx, ny });

                if (nx == r2 && ny == c2) {
                    ans = min(step[nx][ny], ans);
                    q = queue<pair<int, int>>();
                }
            }
        }
    }
}

void setup() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
            temp_grid[i][j] = grid[i][j];
            step[i][j] = 0;
        }
    }
}

vector<int> v;

void choose(int next) {
    if (v.size() == k) {
        setup();

        for (int i = 0; i < k; i++) {
            temp_grid[walls[v[i]].first][walls[v[i]].second] = 0;
        }
        
        visited[r1][c1] = true;
        q.push({ r1, c1 });
        BFS();
        return;
    }

    for (int i = next; i < walls.size(); i++) {
        v.push_back(i);
        choose(i + 1);
        v.pop_back();
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 1) {
                walls.push_back({ i, j });
            }
        }
    }

    cin >> r1 >> c1 >> r2 >> c2;
    r1--; c1--; r2--; c2--;

    choose(0);

    if (ans == INT_MAX) {
        ans = -1;
    }

    cout << ans;
}