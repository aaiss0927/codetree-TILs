#include <iostream>
#include <unordered_map>
using namespace std;

int n;
unordered_map<int, int> mp;

int main() {
	cin >> n;

	while (n--) {
		int x, y; cin >> x >> y;

		if (mp.find(x) != mp.end()) {
			if (y < mp[x]) {
				mp[x] = y;
			}
		}

		else {
			mp[x] = y;
		}
	}

	int ans = 0;

	for (auto it = mp.begin(); it != mp.end(); it++) {
		ans += it->second;
	}

	cout << ans;
}