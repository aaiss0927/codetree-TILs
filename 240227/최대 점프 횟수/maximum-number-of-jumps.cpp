#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dp[1000];
vector<int> table;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int max_jump; cin >> max_jump;
        table.push_back(max_jump);
    }

    for (int i = 0; i < n; i++) {
        dp[i] = -1;
    }

    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (table[j] >= i - j && dp[j] != -1) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    sort(dp, dp + n);

    cout << dp[n - 1];
}