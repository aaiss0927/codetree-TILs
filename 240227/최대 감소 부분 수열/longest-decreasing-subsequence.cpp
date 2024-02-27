#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> nums;
int dp[1001];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        nums.push_back(num);
    }

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[i]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    sort(dp, dp + n);
    cout << dp[n - 1];
}