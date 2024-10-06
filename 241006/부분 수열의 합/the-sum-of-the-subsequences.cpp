#include <iostream>
#include <vector>
using namespace std;

bool dp[101][10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<int> v(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j >= v[i] && dp[i - 1][j - v[i]])
                dp[i][j] = true;

            if (dp[i - 1][j])
                dp[i][j] = true;
        }
    }

    if (dp[n][m])
        cout << "YES";
    else
        cout << "NO";
}