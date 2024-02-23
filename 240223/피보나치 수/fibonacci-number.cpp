#include <iostream>
using namespace std;

int n;
int dp[46];

int f(int n) {
    if (dp[n] != 0) {
        return dp[n];
    }

    if (n <= 2) {
        dp[n] = 1;
    }

    else {
        dp[n] = f(n - 1) + f(n - 2);
    }

    return dp[n];
}

int main() {
    cin >> n;

    cout << f(n);
}