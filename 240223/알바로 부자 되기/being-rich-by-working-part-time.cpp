#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<tuple<int, int, int>> pt;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int s, e, p;
        cin >> s >> e >> p; s--; e--; p;
        pt.push_back({ s, e, p });
    }

    int last_pnt = get<1>(pt.back());

    int* dp = new int[last_pnt + 1];

    for (int i = 0; i <= last_pnt; i++) {
        dp[i] = 0;
        int extra = 0;

        for (int j = 0; j < n; j++) {
            if (get<0>(pt[j]) == 0 && get<1>(pt[j]) == i) {
                extra = get<2>(pt[j]);
            }
        }

        dp[i] += extra;
    }

    for (int i = 1; i <= last_pnt; i++) {
        for (int j = i - 1; j >= 0; j--) {
            int extra = 0;

            for (int k = 0; k < n; k++) {
                if (get<0>(pt[k]) == j + 1 && get<1>(pt[k]) == i) {
                    extra = get<2>(pt[k]);
                }
            }

            dp[i] = max(dp[i], dp[j] + extra);
        }
    }

    cout << dp[last_pnt];
}