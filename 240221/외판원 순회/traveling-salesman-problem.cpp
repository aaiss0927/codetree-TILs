#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int grid[10][10];
int ans = INT_MAX;

vector<int> v;
vector<bool> visited;

void perm(int cur) {
    if (cur == n - 1) {
        if (grid[0][v[0]] == 0) {
            return;
        }

        for (int i = 0; i <= n - 3; i++) {
            if (grid[v[i]][v[i + 1]] == 0) {
                return;
            }
        }

        if (grid[v[n - 2]][0] == 0) {
            return;
        }

        int cost = grid[0][v[0]];

        for (int i = 0; i <= n - 3; i++) {
            cost += grid[v[i]][v[i + 1]];
        }

        cost += grid[v[n - 2]][0];

        ans = min(ans, cost);

        return;
    }

    for (int i = 1; i <= n - 1; i++) {
        if (visited[i]) {
            continue;
        }

        visited[i] = true;
        v.push_back(i);
        perm(cur + 1);
        v.pop_back();
        visited[i] = false;
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    visited = vector<bool>(n, false);

    perm(0);

    cout << ans;
}

// 0 -> -> -> -> ,,, -> 0
// 1 ~ n - 1로 순열 만들기