#include <iostream>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> lines;
int dp[1001];

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) {
        return true;
    }

    else if (p1.second == p2.second) {
        if (p1.first >= p2.first) {
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
    
    for (int i = 0; i < n; i++) {
        int s,e; cin >> s >> e;
        lines.push_back({s, e});
    }

    sort(lines.begin(), lines.end(), cmp);

    int start_pnt, end_pnt;

    start_pnt = lines[0].first;
    end_pnt = lines[0].second;
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        if (lines[i].first > start_pnt) {
            dp[i] = dp[i - 1] + 1;
        }

        else {
            dp[i] = dp[i - 1];
        }
    }

    cout << dp[n - 1];
}