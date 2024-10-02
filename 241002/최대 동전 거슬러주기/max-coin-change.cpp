#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	vector<int> coin(n);
	vector<int> dp(m + 1, INT_MIN);
	dp[0] = 0;

	for (int i = 0; i < n; i++)
		cin >> coin[i];

	for (int i = 1; i <= m; i++) {
		int max = INT_MIN;

		for (int j = 0; j < n; j++) {
			if (i >= coin[j] && dp[i - coin[j]] > max)
				max = dp[i - coin[j]];
		}

		if (max != INT_MIN)
			dp[i] = max + 1;
	}

	if (dp[m] == INT_MIN)
		cout << -1;
	else
		cout << dp[m];
}