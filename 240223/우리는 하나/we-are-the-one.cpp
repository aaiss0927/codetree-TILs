#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <tuple>
using namespace std;

int n, k, u, d;
int grid[8][8];
bool visited[8][8] = {false, };
queue<pair<int, int>> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ans = 0;
int cnt_city;

void setup() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
}

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

    if (abs(grid[x][y] - grid[n_x][n_y]) < u || abs(grid[x][y] - grid[n_x][n_y]) > d) {
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

            if (can_go(x, y, n_x, n_y)) {
                cnt_city++;
                visited[n_x][n_y] = true;
                q.push({n_x, n_y});
            }
        }
    }
}

vector<int> v;

void choose(int next) {
    if (v.size() == k) {
        setup();
        cnt_city = 0;

        for (int i = 0; i < k; i++) {
            if (!visited[v[i] / n][v[i] % n]) {
                cnt_city++;
                visited[v[i] / n][v[i] % n] = true;
                q.push({v[i] / n, v[i] % n});
            }
        }

        BFS();

        ans = max(ans, cnt_city);

        return;
    }

    for (int i = next; i < pow(n, 2); i++) {
        v.push_back(i);
        choose(i + 1);
        v.pop_back();
    }
}

int main() {
    cin >> n >> k >> u >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    choose(0);

    cout << ans;
}