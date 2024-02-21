#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int grid[10][10];
int ans = INT_MIN;

vector<int> v;
bool visited[10];

void perm() {
    if (v.size() == n) {
        int min_value = INT_MAX;

        for (int i = 0; i < n; i++) {
            min_value = min(min_value, grid[i][v[i]]);
        }

        ans = max(ans, min_value);
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }

        visited[i] = true;
        v.push_back(i);
        perm();
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

    perm();

    cout << ans;
}