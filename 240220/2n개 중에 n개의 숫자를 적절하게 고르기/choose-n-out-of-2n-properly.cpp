#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int sum = 0;
int ans = INT_MAX;
vector<int> nums;
vector<int> nums_idx;

// nums = {1, 3, 5, 6}
// nums_idx = {0, 2}

void group(int cur, int next) {
    if (cur == n) {
        int half_sum = 0;
        for (int i = 0; i < n; i++) {
            half_sum += nums[nums_idx[i]];
        }
        int other_sum = sum - half_sum;
        int sub = abs(other_sum - half_sum);
        ans = min(ans, sub);
        return;
    }

    for (int i = next; i < 2 * n; i++) {
        nums_idx.push_back(i);
        group(cur + 1, i + 1);
        nums_idx.pop_back();
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < 2 * n; i++) {
        int num; cin >> num;
        nums.push_back(num);
        sum += num;
    }

    group(0, 0);

    cout << ans;
}