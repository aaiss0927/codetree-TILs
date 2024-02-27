#include <iostream>
#include <climits>
using namespace std;

int n;
int ans = INT_MAX;
int grid[100][100];
int dp[100][100];

void process(int lower) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            dp[i][j] = 101;
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (grid[i][j] < lower) {
                grid[i][j] = 101;
            }
        }
    }

    dp[0][0] = grid[0][0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], grid[i][0]);
    }
    
    for (int j = 1; j < n; j++) {
        dp[0][j] = max(dp[0][j - 1], grid[0][j]);
    }

    for (int i = 1; i < 100; i++) {
        for (int j = 1; j < 100; j++) {
            dp[i][j] = max(min(dp[i - 1][j], dp[i][j - 1]), grid[i][j]);
        }
    }

    if (dp[n - 1][n - 1] == 101) {
        return;
    }

    ans = min(dp[n - 1][n - 1] - lower, ans);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int lower = 1; lower <= 100; lower++) {
        process(lower);
    }

    cout << ans;
}