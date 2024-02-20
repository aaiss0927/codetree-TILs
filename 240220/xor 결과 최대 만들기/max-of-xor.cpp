#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
vector<int> nums;
int ans = INT_MIN;

vector<int> v;

void choose(int cur, int next) {
    if (cur == m) {
        int result = v[0];
        for (int i = 1; i < m; i++) {
            result = result ^ v[i];
        }

        ans = max(ans, result);
        return;
    }

    for (int i = next; i < n; i++) {
        v.push_back(nums[i]);
        choose(cur + 1, i + 1);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        nums.push_back(num);
    }

    choose(0, 0);

    cout << ans;
}