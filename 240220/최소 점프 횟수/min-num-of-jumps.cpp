#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
vector<int> nums;
int ans = INT_MAX;

void process(int cur, int cnt) {
    if (cur == n - 1) {
        ans = min(ans, cnt);
        return;
    }

    if (nums[cur] == 0) {
        cout << -1;
        exit(0);
    }

    for (int i = 1; i <= nums[cur]; i++) {
        if (cur + i <= n - 1) {
            process(cur + i, cnt + 1);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        nums.push_back(num);
    }

    process(0, 0);

    cout << ans;
}