#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	vector<int> v(n);
	vector<int> dp(m + 1);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 1; i <= m; i++)
		dp[i] = INT_MAX;

	for (int i = 0; i < n; i++) {
		for (int j = m; j >= 1; j--) {
			if (j >= v[i] && dp[j - v[i]] != INT_MAX)
				dp[j] = min(dp[j], dp[j - v[i]] + 1);
		}
	}

	if (dp[m] == INT_MAX)
		cout << -1;
	else
		cout << dp[m];
}