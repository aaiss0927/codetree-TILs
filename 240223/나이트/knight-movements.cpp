#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int n;
bool visited[100][100] = {false, };
int step[100][100] = {0, };
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
queue<pair<int, int>> q;

bool in_range(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

bool can_go(int x, int y) {
    return (in_range(x, y) && !visited[x][y]);
}

void BFS() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
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
    cin >> n;

    pair<int, int> s, e;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--; c1--; r2--; c2--;
    s = {r1, c1}; e = {r2, c2};

    visited[r1][c1] = true;
    step[r1][c1] = 0;
    q.push({r1, c1});

    BFS();

    if (step[r2][c2] == 0 && !(r1 == r2 && c1 == c2)) {
        cout << -1;
        return 0;
    }

    cout << step[r2][c2];
}