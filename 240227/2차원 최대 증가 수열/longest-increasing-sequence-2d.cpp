#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int grid[50][50];
int dp[50][50];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 1;

    for (int i = 1; i < n; i++) {
        for (int i_ = 0; i_ < i; i_++) {
            dp[i][0] = -1;
        }
    }

    for (int j = 1; j < m; j++) {
        for (int j_ = 0; j_ < j; j_++) {
            dp[0][j] = -1;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            for (int i_ = 0; i_ < i; i_++) {
                for (int j_ = 0; j_ < j; j_++) {
                    if ((grid[i_][j_] < grid[i][j]) && (dp[i_][j_] != -1)) {
                        dp[i][j] = max(dp[i_][j_] + 1, dp[i][j]);
                    }
                }
            }
        }
    }

    int ans = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
}