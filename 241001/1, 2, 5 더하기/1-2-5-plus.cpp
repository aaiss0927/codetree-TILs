#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> num = { 1, 2, 5 };
	vector<int> dp(n + 1);
	dp[0] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (i >= num[j])
				dp[i] += dp[i - num[j]];
		}
		dp[i] %= 10007;
	}

	cout << dp[n];
}