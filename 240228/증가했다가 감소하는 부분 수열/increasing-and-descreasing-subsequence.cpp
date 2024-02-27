#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
vector<int> nums;
int dp[1001];
int ans = INT_MIN;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        nums.push_back(num);
    }

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    for (int turning_pnt = 0; turning_pnt < n; turning_pnt++) {
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (i <= turning_pnt) {
                    if (nums[j] < nums[i]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }

                else {
                    if (nums[j] > nums[i]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        ans = max(*max_element(dp, dp + n), ans);
    }

    cout << ans;
}