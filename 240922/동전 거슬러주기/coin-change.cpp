#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	vector<int> coin(n);
	vector<int> dp(m + 1);

	for (int i = 1; i <= m; i++)
		dp[i] = INT_MAX;

	for (int i = 0; i < n; i++)
		cin >> coin[i];

	for (int i = 1; i <= m; i++) {
		int min = INT_MAX;

		for (int j = 0; j < n; j++) {
			if (i >= coin[j]) {
				if (dp[i - coin[j]] < min)
					min = dp[i - coin[j]];
			}
		}

		if (min == INT_MAX)
			dp[i] = INT_MAX;
		else
			dp[i] = min + 1;
	}

	if (dp[m] == INT_MAX)
		cout << -1;
	else
		cout << dp[m];
}