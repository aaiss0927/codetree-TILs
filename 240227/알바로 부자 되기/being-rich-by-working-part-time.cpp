#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
vector<tuple<int, int, int>> pts;
pair<int, int> dp[1001];

bool cmp(tuple<int, int, int> t1, tuple<int, int, int> t2) {
    if (get<1>(t1) < get<1>(t2)) {
        return true;
    }

    else if (get<1>(t1) == get<1>(t2)) {
        if (get<0>(t1) > get<0>(t2)) {
            return true;
        }

        else {
            return false;
        }
    }

    return false;
}

int main() {
    cin >> n;

    pts.push_back({ 0, 0, 0 });

    for (int i = 0; i < n; i++) {
        int s, e, p; cin >> s >> e >> p;
        pts.push_back({ s, e, p });
    }

    sort(pts.begin(), pts.end(), cmp);

    for (int i = 1; i <= n; i++) {
        dp[i].first = -1;
        dp[i].second = get<1>(pts[i]);
    }

    dp[1].first = get<2>(pts[1]);
    dp[1].second = get<1>(pts[1]);

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j].first != -1 && dp[j].second < get<0>(pts[i])) {
                if (dp[i].first < dp[j].first + get<2>(pts[i])) {
                    dp[i].first = dp[j].first + get<2>(pts[i]);
                    dp[i].second = get<2>(pts[i]);
                }
            }
        }
    }

    pair<int, int> ans = *max_element(dp, dp + n + 1);
    cout << ans.first;
}