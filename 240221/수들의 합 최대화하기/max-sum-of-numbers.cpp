#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int grid[10][10];
int ans = INT_MIN;

vector<int> v;
vector<bool> visited;

void perm(int cur) {
    if (cur == n) {
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += grid[i][v[i]];
        }

        ans = max(ans, sum);
        return;
    }

    for (int i = 0; i < n; i++) {
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