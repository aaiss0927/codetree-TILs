#include <iostream>
using namespace std;

int n;
int dp[1001];

int process(int n) {
    if (dp[n] != 0) {
        return dp[n];
    }

    if (n == 1) {
        dp[n] = 1;
    }

    else if (n == 2){
        dp[n] = 3;
    }

    else {
        dp[n] = (process(n - 1) + 2 * process(n - 2)) % 10007;
    }

    return dp[n];
}

// dp[n] = dp[n - 1] + 2 * dp[n - 2] (n >= 3)

int main() {
    cin >> n;

    cout << process(n);
}