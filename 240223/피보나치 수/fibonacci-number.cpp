#include <iostream>
using namespace std;

int n;
int dp[46];

int f(int n) {
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    cin >> n;

    dp[1] = dp[2] = 1;

    cout << f(n);
}