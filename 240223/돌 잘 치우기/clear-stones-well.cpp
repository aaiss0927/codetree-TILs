#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int n, m, k;
int grid[100][100];
bool visited[100][100] = {false, };
vector<pair<int, int>> s_pnts;
vector<pair<int, int>> stones;
queue<pair<int, int>> q;
int ans = 0;
int cnt_cell;
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

void BFS() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int n_x = x + dx[i];
            int n_y = y + dy[i];

            if (can_go(n_x, n_y)) {
                cnt_cell++;
                visited[n_x][n_y] = true;
                q.push({n_x, n_y});
            }
        }
    }
}

vector<int> v;

void choose(int next) {
    // m개의 돌 선택
    if (v.size() == m) {
        // m개의 돌 치우기
        for (int i = 0; i < m; i++) {
            grid[stones[v[i]].first][stones[v[i]].second] = 0;
        }
        
        // 현 상황에서 각 시작점에서의 BFS를 위한 setup
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }
        
        cnt_cell = 0;
        
        for (int i = 0; i < s_pnts.size(); i++) {
            if (!visited[s_pnts[i].first][s_pnts[i].second]) {
                cnt_cell++;
                visited[s_pnts[i].first][s_pnts[i].second] = true;
                q.push({s_pnts[i].first, s_pnts[i].second});
            }
        }

        BFS();
        
        ans = max(ans, cnt_cell);
        
        for (int i = 0; i < m; i++) {
            grid[stones[v[i]].first][stones[v[i]].second] = 1;
        }
            
        return;
    }
    
    for (int i = next; i < stones.size(); i++) {
        v.push_back(i);
        choose(i + 1);
        v.pop_back();
    } 
}

int main() {
    cin >> n >> k >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            
            if (grid[i][j] == 1) {
                stones.push_back({i, j});
            }
        }
    }
    
    for (int i = 0; i < k ; i++) {
        int r, c; cin >> r >> c; r--; c--;
        s_pnts.push_back({r, c});
    }

    choose(0);
    
    cout << ans;
}