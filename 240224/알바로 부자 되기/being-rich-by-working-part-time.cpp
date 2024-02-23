#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int n;
pair<int, int> dp[1000];
vector<tuple<int, int, int>> pt;

bool cmp(tuple<int, int, int> t1, tuple<int, int, int> t2) {
    if (get<1>(t1) < get<1>(t2)) {
        return true;
    }

    else if (get<1>(t1) == get<1>(t2)) {
        if (get<0>(t1) <= get<0>(t2)) {
            return true;
        }

        else {
            return false;
        }
    }

    else {
        return false;
    }
}

// 끝점으로 정렬

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int s, e, p;
        cin >> s >> e >> p; s--; e--;
        pt.push_back({ s, e, p });
        dp[i] = {get<1>(pt[i]), get<2>(pt[i])};
    }

    //dp = {last_point, cost}
    sort(pt.begin(), pt.end(), cmp);

    for (int i = 0; i < n; i++) {
        dp[i] = {get<1>(pt[i]), get<2>(pt[i])};
    }

    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            int extra = 0;

            for (int k = 0; k < n; k++) {
                if (get<0>(pt[k]) == dp[j].first + 1 && get<1>(pt[k]) == i) {
                    extra += get<2>(pt[k]);
                }
            }

            dp[i].second = max(dp[i].second, dp[j].second + extra);
        }
    }

    cout << dp[n - 1].second;
}