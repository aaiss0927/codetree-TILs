#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
int r, c;
int grid[100][100];
bool visited[100][100] = {false, };
queue<pair<int, int>> q;
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
    
    if (grid[x][y] >= grid[r][c]) {
        return false;
    }
    
    return true;
}

void BFS() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int n_x = x + dx[i];
            int n_y = y + dy[i];
            
            if (can_go(n_x, n_y)) {
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
    
    cin >> r >> c; r--; c--;
    
    while (k--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;            
            }
        }
        
        visited[r][c] = true;
        q.push({r, c});
        BFS();
        
        int block_size = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) {
                    block_size++;
                }           
            }
        }
        
        if (block_size == 1) {
            break;
        }
        
        int max_value = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] && !(i == r && j == c)) {
                    max_value = max(max_value, grid[i][j]);
                }           
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (visited[i][j] && grid[i][j] == max_value) {
                    r = i; c = j;
                }           
            }
        }
    }
    
    r++; c++;

    cout << r << ' ' << c;
}