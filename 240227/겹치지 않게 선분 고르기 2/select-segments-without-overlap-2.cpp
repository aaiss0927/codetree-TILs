#include <iostream>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> lines;
int dp[1001];

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int s,e; cin >> s >> e;
        lines.push_back({s, e});
    }

    sort(lines.begin(), lines.end());

    for (int i = 0; i < n; i++) {
        dp[i] = 0;
    }

    int start_pnt, end_pnt;

    start_pnt = lines[0].first;
    end_pnt = lines[0].second;
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (lines[j].second < lines[i].first && dp[j] != -1) {
                dp[i] = max(dp[i], dp[j] + 1);
            } 
        }
    }

    cout << *max_element(dp, dp + n);
}