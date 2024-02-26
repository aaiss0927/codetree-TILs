#include <iostream>
#include <algorithm>
using namespace std;

int n;
int grid[100][100];
int dp[100][100];
pair<int, int> Mm[100][100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Mm[0][0] = {grid[0][0], grid[0][0]};

    for (int i = 1; i < n; i++) {
        Mm[i][0] = {max(grid[i][0], Mm[i - 1][0].first), min(grid[i][0], Mm[i - 1][0].second)};
        dp[i][0] = Mm[i][0].first - Mm[i][0].second;
    }

    for (int j = 1; j < n; j++) {
        Mm[0][j] = {max(grid[0][j], Mm[0][j - 1].first), min(grid[0][j], Mm[0][j - 1].second)};
        dp[0][j] = Mm[0][j].first - Mm[0][j].second;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            int select_up, select_left;

            Mm[i][j].first = max(Mm[i - 1][j].first, grid[i][j]);
            Mm[i][j].second = min(Mm[i - 1][j].second, grid[i][j]);
            select_up = Mm[i][j].first - Mm[i][j].second;

            Mm[i][j].first = max(Mm[i][j - 1].first, grid[i][j]);
            Mm[i][j].second = min(Mm[i][j - 1].second, grid[i][j]);
            select_left = Mm[i][j].first - Mm[i][j].second;

            if (select_up <= select_left) {
                Mm[i][j].first = max(Mm[i - 1][j].first, grid[i][j]);
                Mm[i][j].second = min(Mm[i - 1][j].second, grid[i][j]);
            }

            else {
                Mm[i][j].first = max(Mm[i][j - 1].first, grid[i][j]);
                Mm[i][j].second = min(Mm[i][j - 1].second, grid[i][j]);
            }

            dp[i][j] = Mm[i][j].first - Mm[i][j].second;
        }
    }

    cout << dp[n - 1][n - 1];
}