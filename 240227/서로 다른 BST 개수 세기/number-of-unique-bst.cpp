#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int dp[20];


int main() {
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    cout << dp[n];
}